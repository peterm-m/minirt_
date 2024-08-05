/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/05 16:24:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	phong_term(t_light *l, t_hit *h, t_vec4 *color)
{
	float	diff;
	float	spec;

	diff = ft_dotv3(h->secundary.d, h->normal);
	if (islessequal(diff, 0.0f))
		return ;
	spec = ft_dotv3(reflect_dir(&h->normal, &h->primary), h->secundary.d);
	spec = pow(MAX(spec, 0.0f), h->o->material.glossiness);
	rgba_sum(color, ft_mulv4v(l->color, h->data_o[DIFFUSE]), diff);
	rgba_sum(color, ft_mulv4v(l->color, h->data_o[SPECULAR]), spec);
}

static int	env_shading(t_render *r, t_hit *h)
{
	t_vec2	sph;
	t_vec4	color;

	sph.x = 0.5f + atan2f(h->primary.d.z, h->primary.d.x) / (2.0f * M_PI);
	sph.y = 0.5f - asinf(h->primary.d.y) / M_PI;
	color = get_pixel_xpm(r->env, &sph);
	return (rgba_to_int(color));
}

int	shading(t_scene *s, t_hit *h)
{
	t_vec4	pixel_color;
	int		i;

	i = -1;
	pixel_color = ft_mulv4v(h->data_o[AMBIENT], s->a->color);
	while (s->l[++i])
		if (check_shadow(s, h, i))
			phong_term(s->l[i], h, &pixel_color);
	return (rgba_to_int_gamma(pixel_color, 1.1));
}

int	tracer(t_render *r, t_hit *h)
{
	int	color;

	color = 0;
	if (check_hit(r->scene, h))
	{
		surface_info(h);
		color = shading(r->scene, h);
	}
	else if (r->env != NULL)
		color = env_shading(r, h);
	return (color);
}

int	render_loop(t_render *r)
{
	int		color_pixel;
	t_ivec2	pixel;
	t_hit	h;

	clean_canvas(r->canvas);
	pixel.y = -1;
	while (++pixel.y < WIN1_SY)
	{
		pixel.x = -1;
		while (++pixel.x < WIN1_SX)
		{
			gen_camray(&pixel, r->scene->c, &h.primary);
			color_pixel = tracer(r, &h);
			put_pixel(r->canvas, &pixel, color_pixel);
		}
	}
	canvas_to_window(r->canvas);
	mlx_loop_hook(ft_getmlx(), mlx_int_do_nothing, r);
	return (EXIT_SUCCESS);
}
