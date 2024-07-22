/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:29:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	normal_sp(t_hit *h)
{
	t_vec3	v;

	v = ft_subv3(h->pos, h->o->obj.sp.center);
	h->normal = ft_divv3f(v, ft_lenv3(v));
}

void	normal_pl(t_hit *h)
{
	h->normal = h->o->obj.pl.normal;
	if (isgreater(ft_dotv3(h->o->obj.pl.normal, h->primary.d), 0.0f))
		h->normal = ft_mulv3f(h->normal, -1.0f);
}

void	normal_cy(t_hit *h)
{
	t_vec3	p;
	t_vec3	radial;
	float	len;

	p = ft_subv3(h->pos, h->o->obj.cy.center);
	radial = ft_mulv3f(h->o->obj.cy.normal, ft_dotv3(h->o->obj.cy.normal, p));
	radial = ft_subv3(p, radial);
	len = ft_lenv3(radial);
	if (isless(ft_dotv3(radial, h->primary.d), 0.0))
		h->normal = ft_divv3f(radial, len);
	else
		h->normal = ft_divv3f(radial, -1.0f * len);
}

void	normal_cn(t_hit *h)
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
