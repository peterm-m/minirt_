/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 14:42:36 by pedromar         ###   ########.fr       */
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
	h->normal = ft_mulv3f(h->o->obj.pl.normal, \
		ft_dotv3(h->o->obj.pl.normal, h->primary.d));
}

/*
* TODO
*/

static void	normal_cy(t_hit *h)
{
	h->normal = ft_vec3(1.0f, 0.0f, 0.0f);
}

/*
* TODO
*/

static void	normal_cn(t_hit *h)
{
	h->normal = ft_vec3(1.0f, 0.0f, 0.0f);
}
