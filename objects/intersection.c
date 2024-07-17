/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:13:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/17 17:42:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <sys/param.h>

static float	intersection_cy(t_ray *r, t_obj *o);
static float	intersection_cn(t_ray *r, t_obj *o);
static float	intersection_pl(t_ray *r, t_obj *o);
static float	intersection_sp(t_ray *r, t_obj *o);

float	intersection(t_ray *r, t_object *obj)
{
	static float	(*intersections[4])(t_ray *, t_obj *) = {\
		intersection_sp,
		intersection_pl,
		intersection_cy,
		intersection_cn};

	return (intersections[obj->type](r, &obj->obj));
}

static float	intersection_pl(t_ray *r, t_obj *o)
{
	float	to_hit;
	float	nd;
	float	no;

	to_hit = INFINITY;
	nd = ft_dotv3(r->d, o->pl.normal);
	if (!islessgreater(nd, 0.0f))
		return (to_hit);
	no = ft_dotv3(r->o, o->pl.normal);
	to_hit = (o->pl.n_dot_p - no) / nd;
	if (isless(to_hit, 0.0f))
		to_hit = INFINITY;
	return (to_hit);
}

static float	intersection_sp(t_ray *r, t_obj *o)
{
	t_vec3	m;
	float	b;
	float	c;
	float	discriminant;
	float	to_hit;

	to_hit = INFINITY;
	m = ft_subv3(r->o, o->sp.center);
	b = ft_dotv3(m, r->d);
	c = ft_lensqrv3(m) - o->sp.r2;
	discriminant = b * b - c;
	if (isless(discriminant, 0.0f))
		return (to_hit);
	c = sqrt(discriminant);
	to_hit = -b - c;
	if (isless(to_hit, 0.0f))
		to_hit = INFINITY;
	return (to_hit);
}

static float	intersection_cy(t_ray *r, t_obj *o)
{
	t_vec3	oc;
	t_vec3	aux;
	t_vec3	coef;
	float	to_hit;

	oc = ft_subv3(r->o, o->cy.center);
	aux.x = ft_dotv3(o->cy.normal, r->d);
	aux.y = ft_dotv3(o->cy.normal, oc);
	coef.x = 1.0 - aux.x * aux.x;
	coef.y = ft_dotv3(oc, r->d) - aux.y * aux.x;
	coef.z = ft_dotv3(oc, oc) - aux.y * aux.y - o->cy.r2;
	aux.z = coef.y * coef.y - coef.x * coef.z;
	if (aux.z < 0.0f)
		return (INFINITY);
	aux.z = sqrt(aux.z);
	aux.y = ft_dotv3(o->cy.normal, oc);
	to_hit = (- coef.y - aux.z) / coef.x;
	if (!isless(to_hit, 0.0f) && \
		in_range(aux.x * to_hit + aux.y, o->cy.h, 0.0f))
		return (to_hit);
	to_hit = (- coef.y + aux.z) / coef.x;
	if (!isless(to_hit, 0.0f) && \
		in_range(aux.x * to_hit + aux.y, o->cy.h, 0.0f))
		return (to_hit);
	return (INFINITY);
}

/*
* TODO
*/

static float	intersection_cn(t_ray *r, t_obj *o)
{
	(void)r;
	(void)o;
	return (INFINITY);
}
