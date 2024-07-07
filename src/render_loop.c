/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/08 00:46:08 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_trace(t_scene *scene, t_ray *ray, t_hit *hit)
{
	float	aux;
	int		i;

	hit->o = NULL;
	hit->to_hit = INFINITY;
	i = -1;
	while (scene->o[++i])
	{
		aux = intersection(ray, scene->o[i]);
		if (isless(aux, hit->to_hit))
		{
			hit->to_hit = aux;
			hit->o = scene->o[i];
		}
	}
}

int	render_loop(t_render *r)
{
	t_ray	primary;
	t_ivec2	pixel;
	t_hit	h;

	pixel.x = -1;
	while (++pixel.x < WIN1_SX)
	{
		pixel.y = -1;
		while (++pixel.y < WIN1_SY)
		{
			primary_ray(&pixel, r->scene->c, &primary);
			render_trace(r->scene, &primary, &h);
			if (h.o != NULL)
			{
				surface_info(&primary, &h);
				put_pixel(r->canvas, &pixel, rgba_to_int(phong_model(r->scene, &h)));
			}
		}
	}
	canvas_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
