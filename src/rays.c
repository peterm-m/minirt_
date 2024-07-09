/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:35:40 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 20:44:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_position(t_ray *ray)
{
	return (ft_addv3(ft_mulv3f(ray->d, ray->t), ray->o));
}

/*
 * En vez de calcular todos los rayos,
 * calcular el dx y dy de la pantalla 
*/

void	primary_ray(t_ivec2 *pixel, t_camera *c, t_ray *ray)
{
	t_vec2	pixel_ndc;
	t_vec2	pixel_screen;
	t_vec3	dir;

	pixel_ndc.x = (pixel->x + 0.5f) / WIN1_SX;
	pixel_ndc.y = (pixel->y + 0.5f) / WIN1_SY;
	pixel_screen.x = (2.0f * pixel_ndc.x - 1.0f);
	pixel_screen.y = 1.0f - 2.0f * pixel_ndc.y;
	dir.x = pixel_screen.x * WIN1_SX / WIN1_SY * c->fov;
	dir.y = pixel_screen.y ;
	dir.z = -1.0f;
	applay_transformation(&c->cam_world, &dir, &ray->d);
	ray->d = ft_normv3(ray->d);
	ray->o = c->pos;
	ray->t = INFINITY;
}

void	secundary_ray(t_vec3 *from, t_vec3 *to, t_ray *ray)
{
	ray->d = ft_normv3(ft_subv3(*from, *to));
	ray->o = *from;
	ray->t = INFINITY;
}
