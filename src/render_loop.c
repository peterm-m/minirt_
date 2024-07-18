/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/18 14:30:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//#include <time.h>

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

//static clock_t total = 0;
//static	int n_frames = 0;
//clock_t start = clock();
	pixel.y = -1;
	while (++pixel.y < WIN1_SY)
	{
		pixel.x = -1;
		while (++pixel.x < WIN1_SX)
		{
			primary_ray(&pixel, r->scene->c, &h.primary);
			first_hit(r->scene, &h);
			if (h.o != NULL)
				put_pixel(r->canvas, &pixel, shading(r->scene, &h));
			else
				continue ;
		}
	}
	canvas_to_window(r->canvas);
//total += (clock() - start);if (n_frames++ == 10) {printf("Averag time: %ld s %ld ms ", (total/n_frames* 1000 / CLOCKS_PER_SEC) / 1000, (total/n_frames* 1000 / CLOCKS_PER_SEC)%1000);exit (EXIT_SUCCESS);}
return (EXIT_SUCCESS);
}
