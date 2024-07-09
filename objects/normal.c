/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 20:51:10 by pedromar         ###   ########.fr       */
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
	int		is_out;
	t_vec3	v;

	v = ft_subv3(h->pos, h->o->obj.sp.center);
	is_out = isgreater(ft_dotv3(h->primary.o, v), 0.0f);
	h->normal = ft_divv3f(v, ft_lenv3(v) * (!is_out - is_out));
}

static void	normal_pl(t_hit *h)
{
	h->normal = h->o->obj.pl.normal;
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
