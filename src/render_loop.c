/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 19:49:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shading(t_scene *scene, t_hit *h)
{
	static t_xpm	*xpm;if (!xpm)	xpm = ft_xpm_image("/home/pedromar/code/minirt_/files_xpm/tierra.xpm");
	t_vec4	color;
	int		i;

	color = scene->a->color;
	surface_info(h);
	i = -1;
	while (scene->l[++i])
	{
		gen_ray(h->pos, scene->l[i]->pos, &h->secundary);
		if (check_shadow(scene, h))
			continue ;
		phong_term(scene->l[i], h, &color);
	}
	
	return (rgba_to_int(ft_mulv4v(get_pixel_xpm(xpm, &h->texture), color)));
}

int	render_loop(t_render *r)
{
	t_ivec2	pixel;
	t_hit	h;
	static t_xpm	*xpm; if (!xpm) 	xpm = ft_xpm_image("/home/pedromar/code/minirt_/files_xpm/env.xpm");
INIT_CLOCK
	pixel.y = -1;
	while (++pixel.y < WIN1_SY)
	{
		pixel.x = -1;
		while (++pixel.x < WIN1_SX)
		{
			gen_camray(&pixel, r->scene->c, &h.primary);
			check_hit(r->scene, &h);
			if (h.o != NULL)
				put_pixel(r->canvas, &pixel, shading(r->scene, &h));
			else
			{
				put_pixel(r->canvas, &pixel, rgba_to_int(get_pixel_xpm(xpm, &(t_vec2){.x = (0.5f + atan2f(h.primary.d.z, h.primary.d.x) / (2.0f * M_PI)), .y = (0.5f - asinf( h.primary.d.y) / M_PI)})));
				continue ;
			}
		}
	}
	canvas_to_window(r->canvas);
END_CLOCK(1, false);
	return (EXIT_SUCCESS);
}
