/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:33:01 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 18:18:45 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "minirt.h"

void	bound_object(t_object *obj)
{
	static void	(*bounds[6])(t_object *) = {\
		bound_sp,
		bound_pl,
		bound_cy,
		bound_qd,
		bound_disk,
		bound_tr};

	bounds[obj->type](obj);
}

void	bound_cy(t_object *o)
{
	t_vec3	a;
	t_vec3	pb;
	t_vec3	pa;

	pa = o->obj.cy.center;
	pb = ft_addv3(pa, ft_mulv3f(o->obj.cy.normal, o->obj.cy.h));
	a = ft_mulv3v(o->obj.cy.normal, o->obj.cy.normal);
	a = ft_mulv3f(a, o->obj.cy.r2 / (o->obj.cy.h * o->obj.cy.h));
	a = ft_subv3(ft_vec3(o->obj.cy.r2, o->obj.cy.r2, o->obj.cy.r2), a);
	a = ft_toeachv3(a, sqrtf);
	o->bound.p_max.x = MIN(pa.x - a.x, pb.x - a.x);
	o->bound.p_max.y = MIN(pa.y - a.y, pb.y - a.y);
	o->bound.p_max.z = MIN(pa.z - a.z, pb.z - a.z);
	o->bound.p_min.x = MAX(pa.x + a.x, pb.x + a.x);
	o->bound.p_min.y = MAX(pa.y + a.y, pb.y + a.y);
	o->bound.p_min.z = MAX(pa.z + a.z, pb.z + a.z);
}

void	bound_qd(t_object *o)
{
	int			i;
	t_vec3		aux[2];
	t_vec4		v;
	t_matrix4	c;

	aux[0] = o->obj.qd.bound_body.p_min;
	aux[1] = o->obj.qd.bound_body.p_max;
	c = get_transform(ft_vec3(0, 0, 0), o->obj.qd.angles, ft_vec3(1, 1, 1));
	o->bound.p_max = ft_vec3(-INFINITY, -INFINITY, -INFINITY);
	o->bound.p_min = ft_vec3(INFINITY, INFINITY, INFINITY);
	i = -1;
	while (++i < 8)
	{
		v = ft_mulm4v(c, ft_vec4(aux[(i & 1) == 0].x, \
			aux[(i & 2) == 0].y, \
			aux[(i & 4) == 0].z, 1.0f));
		o->bound.p_max.x = MAX(o->bound.p_max.x, o->obj.qd.center.x + v.x);
		o->bound.p_max.y = MAX(o->bound.p_max.y, o->obj.qd.center.y + v.y);
		o->bound.p_max.z = MAX(o->bound.p_max.z, o->obj.qd.center.z + v.z);
		o->bound.p_min.x = MIN(o->bound.p_min.x, o->obj.qd.center.x + v.x);
		o->bound.p_min.y = MIN(o->bound.p_min.y, o->obj.qd.center.y + v.y);
		o->bound.p_min.z = MIN(o->bound.p_min.z, o->obj.qd.center.z + v.z);
	}
}


void	bound_pl(t_object *o)
{
	o->bound.p_max = ft_vec3(INFINITY, INFINITY, INFINITY);
	o->bound.p_min = ft_vec3(INFINITY,INFINITY, INFINITY);
}

void	bound_sp(t_object *o)
{
	float	r;

	r = sqrtf(o->obj.sp.r2);
	o->bound.p_max = ft_addv3(o->obj.sp.center, ft_vec3(r, r, r));
	o->bound.p_min = ft_addv3(o->obj.sp.center, ft_vec3(-r, -r, -r));
}
