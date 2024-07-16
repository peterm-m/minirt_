/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/16 19:45:29 by pedromar         ###   ########.fr       */
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

/*
* TODO
*/

static void	normal_cy(t_hit *h)
{
	t_vec3	v;
	float	v_dot_n;

	v = ft_subv3(h->pos, h->o->obj.sp.center);
	v_dot_n = ft_dotv3(h->o->obj.cy.normal, v);
	h->normal = ft_subv3(v, ft_mulv3f(h->o->obj.cy.normal, v_dot_n));
	h->normal = ft_normv3(h->normal);
}

/*
* TODO
*/

static void	normal_cn(t_hit *h)
{
	h->normal = ft_vec3(1.0f, 0.0f, 0.0f);
}
