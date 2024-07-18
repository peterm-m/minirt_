/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:33:01 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/18 12:10:12 by pedromar         ###   ########.fr       */
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
static void	bound_cube(t_object *o);

void	bound_object(t_object *obj)
{
	static void	(*bounds[8])(t_object *) = {\
		bound_sp,
		bound_pl,
		bound_cy,
		bound_cn,
		bound_disk,
		bound_tr,
		bound_sq,
		bound_cube};

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
	a.x = sqrtf(a.x);
	a.y = sqrtf(a.y);
	a.z = sqrtf(a.z);
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
	pb = ft_addv3(pa, ft_mulv3f(o->obj.cn.normal, o->obj.cn.h));
	a = ft_mulv3v(o->obj.cn.normal, o->obj.cn.normal);
	a = ft_divv3f(a, o->obj.cn.h * o->obj.cn.h);
	a = ft_subv3(ft_vec3(1.0f, 1.0f ,1.0f), a);
	a.x = sqrtf(a.x);
	a.y = sqrtf(a.y);
	a.z = sqrtf(a.z);
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
	a.x = sqrtf(a.x);
	a.y = sqrtf(a.y);
	a.z = sqrtf(a.z);
	a = ft_mulv3f(a, r);
	o->bound.p_max = ft_addv3(o->obj.disk.center, a);
	o->bound.p_min = ft_subv3(o->obj.disk.center, a);
}

/*
* TODO
*/

static void	bound_sq(t_object *o)
{
	(void)o;
	return;
}

/*
* TODO
*/

static void	bound_cube(t_object *o)
{
	(void)o;
	return;
}

/*
* TODO
*/

static void	bound_tr(t_object *o)
{
	(void)o;
	return;
}
