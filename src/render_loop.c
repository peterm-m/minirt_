/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 13:58:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	first_hit(t_scene *scene, t_hit *hit)
{
	float	aux;
	int		i;

	hit->o = NULL;
	i = -1;
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

/*
 * Solo calular los pixeles que hay que refrescar
 * mover el resto
 */
# include "mlx.h"
# include "mlx_int.h"

int	render_loop(t_render *r)
{
	t_ivec2	pixel;
	t_hit	h;

	pixel.x = -1;
	while (++pixel.x < WIN1_SX)
	{
		pixel.y = -1;
		while (++pixel.y < WIN1_SY)
		{
			primary_ray(&pixel, r->scene->c, &h.primary);
			first_hit(r->scene, &h);
			if (h.o != NULL)
				put_pixel(r->canvas, &pixel, phong_model(r->scene, &h));
		}
	}
	canvas_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
