/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_to_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:03:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/08 18:03:17 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	lights_to_cam(t_light **l, t_camera *c)
{
	int	i;

	i = -1;
	while (l[++i])
		l[i]->pos = ft_subv3(l[i]->pos, c->pos);
}

static void	object_to_cam(t_object **o, t_camera *c)
{
	int	i;

	i = -1;
	while (o[++i])
	{
		if (o[i]->type == obj_cylinder)
			o[i]->obj.cy.center = ft_subv3(o[i]->obj.cy.center, c->pos);
		else if (o[i]->type == obj_sphere)
			o[i]->obj.sp.center = ft_subv3(o[i]->obj.sp.center, c->pos);
		else if (o[i]->type == obj_plane)
		{
			o[i]->obj.pl.p = ft_subv3(o[i]->obj.pl.p, c->pos);
			o[i]->obj.pl.n_dot_p = ft_dotv3(o[i]->obj.pl.p, o[i]->obj.pl.normal);
		}
		bound_object(o[i]);
	}
}

static void	cams_to_cam(t_camera **cs, t_camera *c)
{
	int	i;

	i = -1;
	while (cs[++i])
		cs[i]->pos = ft_subv3(cs[i]->pos, c->pos);
}

void	scene_to_cam(t_scene *s)
{
	lights_to_cam(s->l, s->c);
	object_to_cam(s->o, s->c);
	cams_to_cam(s->cs, s->c);
}
