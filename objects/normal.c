/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 18:53:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	normal(t_hit *h)
{
	float		norm_factor;
	static void	(*normals[6])(t_hit *) = {\
		normal_sp,
		normal_pl,
		normal_cy,
		normal_qd,
		normal_disk,
		normal_tr};

	normals[h->o->type](h);
	norm_factor = 1.0f / ft_lenv3(h->normal);
	if (isgreater(ft_dotv3(h->normal, h->primary.d), 0.0f))
		norm_factor *= -1.0f;
	h->normal = ft_mulv3f(h->normal, norm_factor);
}

void	normal_sp(t_hit *h)
{
	h->normal = ft_subv3(h->pos, h->o->obj.sp.center);
}

void	normal_pl(t_hit *h)
{
	h->normal = h->o->obj.pl.normal;
}

void	normal_cy(t_hit *h)
{
	t_vec3	p;
	t_vec3	radial;

	p = ft_subv3(h->pos, h->o->obj.cy.center);
	radial = ft_mulv3f(h->o->obj.cy.normal, ft_dotv3(h->o->obj.cy.normal, p));
	h->normal = ft_subv3(p, radial);
}

void	normal_qd(t_hit *h)
{
	t_vec3		p;
	t_matrix4	a;

	p = h->pos;
	a = h->o->obj.qd.a;
	h->normal.x = 2.0f * a.elements[0][0] * p.x \
		+ (a.elements[0][1] + a.elements[1][0]) * p.y \
		+ (a.elements[0][2] + a.elements[2][0]) * p.z \
		+ (a.elements[0][3] + a.elements[3][0]);
	h->normal.y = p.x * (a.elements[0][1] + a.elements[1][0]) \
		+ 2.0f * p.y * a.elements[1][1] \
		+ p.z * (a.elements[1][2] + a.elements[2][1]) \
		+ (a.elements[1][3] + a.elements[3][1]);
	h->normal.z = p.x * (a.elements[0][2] + a.elements[2][0]) \
		+ p.y * (a.elements[1][2] + a.elements[2][1]) \
		+ 2.0f * p.z * a.elements[2][2] \
		+ (a.elements[2][3] + a.elements[3][2]);
}
