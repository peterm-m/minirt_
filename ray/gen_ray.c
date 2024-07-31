/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:35:40 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 18:56:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	gen_camray(t_ivec2 *pixel, t_camera *c, t_ray *ray)
{
	t_vec2	pixel_ndc;
	t_vec2	pixel_screen;
	t_vec3	dir;

	pixel_ndc.x = (pixel->x + 0.5f) / WIN1_SX;
	pixel_ndc.y = (pixel->y + 0.5f) / WIN1_SY;
	pixel_screen.x = 2.0f * pixel_ndc.x - 1.0f;
	pixel_screen.y = 2.0f * pixel_ndc.y - 1.0f;
	dir.x = pixel_screen.x * WIN1_SX / WIN1_SY * c->fov;
	dir.y = pixel_screen.y ;
	dir.z = -1.0f;
	transform_dir(&c->cam_world, &dir, &ray->d);
	ray->d = ft_normv3(ray->d);
	ray->o = ft_vec3(0,0,0);
	ray->t = INFINITY;
}

void	gen_ray(t_vec3 pos_hit, t_vec3 pos_light, t_ray *ray)
{
	t_vec3	light2hit;

	light2hit = ft_subv3(pos_light, pos_hit);
	ray->t = ft_lenv3(light2hit);
	ray->d = ft_divv3f(light2hit, ray->t);
	ray->o = pos_hit;
}
