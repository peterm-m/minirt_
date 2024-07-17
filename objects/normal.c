/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/17 17:42:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	normal_sp(t_hit *h);
static void	normal_pl(t_hit *h);
static void	normal_cy(t_hit *h);
static void	normal_cn(t_hit *h);

void	normal(t_hit *h)
{
	static void	(*normals[4])(t_hit *) = {\
		normal_sp,
		normal_pl,
		normal_cy,
		normal_cn};

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
	radial = ft_subv3(p, ft_mulv3f(h->o->obj.cy.normal, to_base));
	to_axis = ft_dotv3(radial, radial);
	if (isgreater(ft_dotv3(h->o->obj.cy.normal, h->primary.d), 0.0))
		h->normal = ft_divv3f(radial, to_axis);
	else
		h->normal = ft_divv3f(radial, -1.0f * to_axis);
}

/*
* TODO
*/

static void	normal_cn(t_hit *h)
{
	h->normal = ft_vec3(1.0f, 0.0f, 0.0f);
}
