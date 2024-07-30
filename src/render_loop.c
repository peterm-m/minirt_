/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 19:33:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	return (rgba_to_int(pixel_color));
}

int	render_loop(t_render *r)
{
	t_ivec2	pixel;
	t_hit	h;
t_vec2 a = {.x = 0.5, .y =  0.5};
//INIT_CLOCK
	pixel.y = -1;
	while (++pixel.y < WIN1_SY)
	{
		pixel.x = -1;
		while (++pixel.x < WIN1_SX)
		{
			gen_camray(&pixel, r->scene->c, &h.primary);
			if (check_hit(r->scene, &h))
				put_pixel(r->canvas, &pixel, shading(r->scene, &h));
			else if (r->env)
				put_pixel(r->canvas, &pixel, rgba_to_int(get_pixel_xpm(r->env, &a)));
		}
	}
	canvas_to_window(r->canvas);
	mlx_loop_hook(ft_getmlx(), mlx_int_do_nothing, r);
//END_CLOCK(5, true);
	return (EXIT_SUCCESS);
}
