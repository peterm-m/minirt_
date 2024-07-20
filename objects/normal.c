/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 23:36:55 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	normal_sp(t_hit *h);
static void	normal_pl(t_hit *h);
static void	normal_cy(t_hit *h);
static void	normal_cn(t_hit *h);
static void	normal_disk(t_hit *h);
static void	normal_tr(t_hit *h);

void	normal(t_hit *h)
{
	static void	(*normals[6])(t_hit *) = {\
		normal_sp,
		normal_pl,
		normal_cy,
		normal_cn,
		normal_disk,
		normal_tr};

	normals[h->o->type](h);
}

static void	normal_sp(t_hit *h)
{
	t_vec3	v;

	v = ft_subv3(h->pos, h->o->obj.sp.center);
	h->normal = ft_divv3f(v, ft_lenv3(v));
}

static void	normal_pl(t_hit *h)
{
	h->normal = h->o->obj.pl.normal;
	if (isgreater(ft_dotv3(h->o->obj.pl.normal, h->primary.d), 0.0f))
		h->normal = ft_mulv3f(h->normal, -1.0f);
}

static void	normal_cy(t_hit *h)
{
	t_vec3	p;
	t_vec3	radial;
	float	to_axis;
	float	to_base;

	p = ft_subv3(h->pos, h->o->obj.sp.center);
	to_base = ft_dotv3(h->o->obj.cy.normal, p);
	radial = ft_fmav3f(h->o->obj.cy.normal, -1.0f * to_base, p);
	to_axis = ft_dotv3(radial, radial);
	if (!isgreater(ft_dotv3(radial, h->primary.d), 0.0))
		h->normal = ft_divv3f(radial, to_axis);
	else
		h->normal = ft_divv3f(radial, -1.0f * to_axis);
}

static void	normal_cn(t_hit *h)
{
	t_vec3	cp;
	float	a;

	cp = ft_subv3(h->pos, h->o->obj.cn.center);
	a = ft_dotv3(cp, h->o->obj.cn.normal) / ft_dotv3(cp, cp);
	h->normal = ft_fmav3f(cp, a, h->o->obj.cn.normal);
	a = ft_lenv3(h->normal);
	if (!isgreater(ft_dotv3(h->normal, h->primary.d), 0.0))
		h->normal = ft_divv3f(h->normal, a);
	else
		h->normal = ft_divv3f(h->normal, -1.0f * a);
}

static void	normal_disk(t_hit *h)
{
	h->normal = h->o->obj.disk.normal;
	if (isless(ft_dotv3(h->o->obj.disk.normal, h->primary.d), 0.0))
		h->normal = ft_divv3f(h->normal, -1.0f);
}

static void	normal_tr(t_hit *h)
{
	t_vec3	normal;
	float	a;

	normal = ft_cross(h->o->obj.tr.v0, h->o->obj.tr.v1);
	a = ft_lenv3(normal);
	if (!isgreater(ft_dotv3(normal, h->primary.d), 0.0))
		h->normal = ft_divv3f(normal, a);
	else
		h->normal = ft_divv3f(normal, -1.0f * a);
	return;
}
