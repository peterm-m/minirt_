/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:33:01 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 17:23:45 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
# include <sys/param.h>

static void	bound_cy(t_object *o);
static void	bound_cn(t_object *o);
static void	bound_pl(t_object *o);
static void	bound_sp(t_object *o);
static void	bound_disk(t_object *o);
static void	bound_tr(t_object *o);
static void	bound_sq(t_object *o);

void	bound_object(t_object *obj)
{
	static void	(*bounds[7])(t_object *) = {\
		bound_sp,
		bound_pl,
		bound_cy,
		bound_cn,
		bound_disk,
		bound_tr,
		bound_sq};

	bounds[obj->type](obj);
}

static void	bound_cy(t_object *o)
{
	t_vec3	a;
	t_vec3	pb;
	t_vec3	pa;

	pa = o->obj.cy.center;
	pb = ft_addv3(pa, ft_mulv3f(o->obj.cy.normal, o->obj.cy.h));
	a = ft_mulv3v(o->obj.cy.normal, o->obj.cy.normal);
	a = ft_mulv3f(a, o->obj.cy.r2 / (o->obj.cy.h * o->obj.cy.h));
	a = ft_subv3(ft_vec3(o->obj.cy.r2, o->obj.cy.r2 ,o->obj.cy.r2), a);
	a = ft_toeachv3(a, sqrtf);
	o->bound.p_max.x = MIN(pa.x - a.x, pb.x - a.x);
	o->bound.p_max.y = MIN(pa.y - a.y, pb.y - a.y);
	o->bound.p_max.z = MIN(pa.z - a.z, pb.z - a.z);
	o->bound.p_min.x = MAX(pa.x + a.x, pb.x + a.x);
	o->bound.p_min.y = MAX(pa.y + a.y, pb.y + a.y);
	o->bound.p_min.z = MAX(pa.z + a.z, pb.z + a.z);
}

static void	bound_cn(t_object *o)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	pb;
	t_vec3	pa;

	pa = o->obj.cn.center;
	pb = ft_fmav3f(o->obj.cn.normal, o->obj.cn.h, pa);
	a = ft_mulv3v(o->obj.cn.normal, o->obj.cn.normal);
	a = ft_divv3f(a, o->obj.cn.h * o->obj.cn.h);
	a = ft_subv3(ft_vec3(1.0f, 1.0f ,1.0f), a);
	a = ft_toeachv3(a, sqrtf);
	b = ft_mulv3f(a, o->obj.cn.rb);
	a = ft_mulv3f(a, o->obj.cn.ra);
	o->bound.p_max.x = MIN(pa.x - a.x, pb.x - b.x);
	o->bound.p_max.y = MIN(pa.y - a.y, pb.y - b.y);
	o->bound.p_max.z = MIN(pa.z - a.z, pb.z - b.z);
	o->bound.p_min.x = MAX(pa.x + a.x, pb.x + b.x);
	o->bound.p_min.y = MAX(pa.y + a.y, pb.y + b.y);
	o->bound.p_min.z = MAX(pa.z + a.z, pb.z + b.z);
}

static void	bound_pl(t_object *o)
{
	o->bound.p_max = ft_vec3(INFINITY, INFINITY, INFINITY);
	o->bound.p_min = ft_vec3(0.0f, 0.0f, 0.0f);
}

static void	bound_sp(t_object *o)
{
	float	r;

	r = sqrtf(o->obj.sp.r2);
	o->bound.p_max = ft_addv3(o->obj.sp.center, ft_vec3(r, r, r));
	o->bound.p_min = ft_addv3(o->obj.sp.center, ft_vec3(-r, -r, -r));
}

static void	bound_disk(t_object *o)
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

/*
* TODO
*/

static void	bound_sq(t_object *o)
{
	(void)o;
	return;
}

static void	bound_tr(t_object *o)
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
