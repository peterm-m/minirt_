/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:13:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/07 12:04:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	intersection_box(t_ray *r, t_obj *o)
{
	t_matrix4	world_obj;
	t_ray		r_obj;

	world_obj = get_invtransform(o->qd.center, o->qd.angles, ft_vec3(1, 1, 1));
	r_obj.d = ft_mulm4v(world_obj, ft_vec4(r->d.x, r->d.y, r->d.z, 0.0f)).xyz;
	r_obj.o = ft_mulm4v(world_obj, ft_vec4(r->o.x, r->o.y, r->o.z, 1.0f)).xyz;
	return (bound_check(&r_obj, &o->qd.bound_body));
}
