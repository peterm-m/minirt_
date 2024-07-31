/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 15:23:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	env_shading(t_render *r, t_hit *h)
{
	t_vec2	sph;
	t_vec4	color;

	sph.x = 0.5f + atan2f(h->primary.d.z, h->primary.d.x) / (2.0f * M_PI);
	sph.y = 0.5f - asinf(h->primary.d.y) / M_PI;
	color = get_pixel_xpm(r->env, &sph);
	return (rgba_to_int(color));
}

int	shading(t_scene *scene, t_hit *h)
{
	t_vec4	pixel_color;
	int		i;

	i = -1;
	surface_info(h);
	pixel_color = ft_mulv4v(h->data_o[AMBIENT], scene->a->color);
	while (scene->l[++i])
		if (check_shadow(scene, h, i))
			phong_term(scene->l[i], h, &pixel_color);
	return (rgba_to_int_gamma(pixel_color, 1.1));
}

int	render_loop(t_render *r)
{
	t_ivec2	pixel;
	t_hit	h;

	ft_bzero(r->canvas->data, \
		WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
	pixel.y = -1;
	while (++pixel.y < WIN1_SY)
	{
		pixel.x = -1;
		while (++pixel.x < WIN1_SX)
		{
			gen_camray(&pixel, r->scene->c, &h.primary);
			if (check_hit(r->scene, &h))
				put_pixel(r->canvas, &pixel, shading(r->scene, &h));
			else if (r->env != NULL)
				put_pixel(r->canvas, &pixel, env_shading(r, &h));
		}
	}
	canvas_to_window(r->canvas);
	mlx_loop_hook(ft_getmlx(), mlx_int_do_nothing, r);
	return (EXIT_SUCCESS);
}
