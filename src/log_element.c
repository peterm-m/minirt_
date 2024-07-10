/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:23:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 18:40:17 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	log_scene(t_scene *s)
{
	int	i;

	log_camera(s->c);
	log_ambient(s->a);
	i = -1;
	while (s->l[++i])
		log_light(s->l[i]);
	i = -1;
	while (s->o[++i])
		log_object(s->o[i]);
}

void	log_ambient(t_ambient *a)
{
	printf("ambient: ratio = %f; rgba = (%f, %f, %f, %f)\n",
	a->ratio,
	a->color.r, a->color.g, a->color.b, a->color.a);
}

void	log_camera(t_camera *c)
{
	printf("camera:  pos = (%f, %f, %f);  normal = (%f, %f, %f); fov = %f;\n cam_world = \n",
	c->pos.x, c->pos.y, c->pos.z,
	c->normal.x, c->normal.y, c->normal.z,
	c->fov);
	printm4(c->cam_world);
}

void	log_light(t_light *l)
{
	printf("light: pos = (%f, %f, %f); ratio = %f; rgba = (%f, %f, %f, %f)\n",
	l->pos.x, l->pos.y, l->pos.z, 
	l->ratio,
	l->color.r, l->color.g, l->color.b, l->color.a);
}
