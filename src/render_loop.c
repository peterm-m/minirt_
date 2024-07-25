/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */


/*   Updated: 2024/07/25 19:19:00 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shading(t_scene *scene, t_hit *h)
{
	t_vec4	light_color;
	int		i;

	i = -1;
	surface_info(h);
	light_color = scene->a->color; // mas componente emisiva del cuerpo
	while (scene->l[++i])
		if (check_shadow(scene, h, i))
			phong_term(scene->l[i], h, &light_color);
	return (rgba_to_int(ft_mulv4v(h->o->color, light_color)));
}

int	render_loop(t_render *r)
{
	t_ivec2	pixel;
	t_hit	h;

INIT_CLOCK
	pixel.y = -1;
	while (++pixel.y < WIN1_SY)
	{
		pixel.x = -1;
		while (++pixel.x < WIN1_SX)
		{
			gen_camray(&pixel, r->scene->c, &h.primary);
			if (check_hit(r->scene, &h))
				put_pixel(r->canvas, &pixel, shading(r->scene, &h));
		}
	}
	canvas_to_window(r->canvas);
	//mlx_loop_hook(ft_getmlx(), mlx_int_do_nothing, r);
END_CLOCK(1, false);
	return (EXIT_SUCCESS);
}
