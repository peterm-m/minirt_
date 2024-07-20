/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:33:01 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:26:14 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	bound_disk(t_object *o)
{
	t_vec3	a;
	float	r;

	r = sqrtf(o->obj.disk.r2);
	a = ft_mulv3v(o->obj.disk.normal, o->obj.disk.normal);
	a = ft_subv3(ft_vec3(1.0f, 1.0f, 1.0f), a);
	a = ft_toeachv3(a, sqrtf);
	o->bound.p_max = ft_fmav3f(a, r, o->obj.disk.center);
	o->bound.p_min = ft_fmav3f(a, -1.0f * r, o->obj.disk.center);
}

void	bound_tr(t_object *o)
{
	t_vec3	v0;
	t_vec3	v1;
	t_vec3	v2;

	v0 = o->obj.tr.v0;
	v1 = o->obj.tr.v1;
	v2 = o->obj.tr.v2;
	o->bound.p_max.x = MAX(v0.x, v1.x);
	o->bound.p_max.x = MAX(o->bound.p_max.x, v2.x);
	o->bound.p_max.y = MAX(v0.y, v1.y);
	o->bound.p_max.y = MAX(o->bound.p_max.y, v2.y);
	o->bound.p_max.z = MAX(v0.z, v1.z);
	o->bound.p_max.z = MAX(o->bound.p_max.z, v2.z);
	o->bound.p_min.x = MIN(v0.x, v1.x);
	o->bound.p_min.x = MIN(o->bound.p_min.x, v2.x);
	o->bound.p_min.y = MIN(v0.y, v1.y);
	o->bound.p_min.y = MIN(o->bound.p_min.y, v2.y);
	o->bound.p_min.z = MIN(v0.z, v1.z);
	o->bound.p_min.z = MIN(o->bound.p_min.z, v2.z);
}
