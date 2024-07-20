/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 00:32:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	first_hit(t_scene *scene, t_hit *hit)
{
	float	aux;
	int		i;

	i = -1;
	hit->o = NULL;
	while (scene->o[++i])
	{
		aux = intersection(&hit->primary, scene->o[i]);
		if (isfinite(aux) && isless(aux, hit->primary.t))
		{
			hit->primary.t = aux;
			hit->o = scene->o[i];
		}
	}
}

int	render_loop(t_render *r)
{
	t_ivec2	pixel;
	t_hit	h;
	//static t_xpm	*xpm;
	//if (!xpm)
	//	xpm = ft_xpm_image("/home/pedro/repos/minirt_/files_xpm/env.xpm");	
INIT_CLOCK
	pixel.y = -1;
	while (++pixel.y < WIN1_SY)
	{
		pixel.x = -1;
		while (++pixel.x < WIN1_SX)
		{
			gen_primary(&pixel, r->scene->c, &h.primary);
			first_hit(r->scene, &h);
			if (h.o != NULL)
				put_pixel(r->canvas, &pixel, shading(r->scene, &h));
			else
			//{
			//	put_pixel(r->canvas, &pixel, get_pixel_xpm(xpm, (t_ivec2){\
			//		.x = xpm->h * (0.5f + atan2f(h.primary.d.z, h.primary.d.x) / (2.0f * M_PI)),\
			//		.y = xpm->w *(0.5f - asinf( h.primary.d.y) / M_PI)}));
				continue ;
			//}
		}
	}
	canvas_to_window(r->canvas);
END_CLOCK(1, false);
	return (EXIT_SUCCESS);
}
