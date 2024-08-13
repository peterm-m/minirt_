/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:42:32 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/08 20:28:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transform_light(t_matrix4 *m, t_light *l)
{
	transform_vec(m, &l->pos, &l->pos);
}

void	transform_camera(t_matrix4 *m, t_camera *c)
{
	float	z_normal;

	z_normal = c->normal.z;
	transform_vec(m, &c->pos, &c->pos);
	transform_dir(m, &c->normal, &c->normal);
	c->cam_world = lookatl(\
		ft_subv3(c->pos, c->normal), \
		ft_vec3(0.0f, (z_normal != 0), (z_normal == 0)), c->pos);
}

void	transform_scene(t_matrix4 *m, t_scene *s)
{
	int			i;

	i = -1;
	while (s->l[++i])
		transform_light(m, s->l[i]);
	i = -1;
	while (s->o[++i])
		transform_object(m, s->o[i]);
	i = -1;
	while (s->cs[++i])
		transform_camera(m, s->cs[i]);
}
