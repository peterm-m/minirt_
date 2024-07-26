/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:13:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/26 18:55:32 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	intersection_disk(t_ray *r, t_obj *o)
{
	t_vec3	a;
	float	t;

	a = ft_subv3(r->o, o->disk.center);
	t = -ft_dotv3(a, o->disk.normal) / ft_dotv3(r->d, o->disk.normal);
	a = ft_addv3(a, ft_mulv3f(r->d, t));
	if (isgreater(ft_dotv3(a, a), o->disk.r2))
		return (INFINITY);
	return (t);
}

float	intersection_tr(t_ray *r, t_obj *o)
{
	t_vec3	diffs[3];
	t_vec3	cross_products[2];
	t_vec4	aux;

	diffs[0] = ft_subv3(o->tr.v1, o->tr.v0);
	diffs[1] = ft_subv3(o->tr.v2, o->tr.v0);
	diffs[2] = ft_subv3(r->o, o->tr.v0);
	cross_products[0] = ft_cross(diffs[0], diffs[1]);
	cross_products[1] = ft_cross(diffs[2], r->d);
	aux.x = 1.0 / ft_dotv3(r->d, cross_products[0]);
	aux.y = aux.x * ft_dotv3(ft_mulv3f(cross_products[1], -1.0f), diffs[1]);
	aux.z = aux.x * ft_dotv3(cross_products[1], diffs[0]);
	aux.w = aux.x * ft_dotv3(ft_mulv3f(cross_products[0], -1.0f), diffs[2]);
	if (aux.y < 0.0 || aux.z < 0.0 || (aux.y + aux.z) > 1.0)
		return (INFINITY);
	return (aux.w);
}

//float	intersection_qd(t_ray *r, t_obj *o)
//{
//	t_vec4	p;
//	t_vec4	p1;
//	t_vec4	coef;
//	float	to_hit[2];
//
//	p.xyz = r->d;
//	p.w = 1.0f;
//	p1.xyz = r->o;
//	p1.w = 1.0f;
//	coef.x = ft_dotv4(p, ft_mulm4v(o->qd.a, p));
//	coef.y = ft_dotv4(p, ft_mulm4v(o->qd.a, p1));
//	coef.y += ft_dotv4(p1, ft_mulm4v(o->qd.a, p));
//	coef.z = ft_dotv4(p1, ft_mulm4v(o->qd.a, p1));
//	coef.w = coef.y * coef.y - 4.0f * coef.x * coef.z;
//	if (isless(coef.w, 0.0f))
//		return (INFINITY);
//	coef.w = sqrtf(coef.w);
//	to_hit[0] = (-coef.y - coef.w) / (2.0f * coef.x);
//	to_hit[1] = (-coef.y + coef.w) / (2.0f * coef.x);
//	to_hit[0] *= isless(to_hit[0], 0.0f);
//	to_hit[1] *= isless(to_hit[1], 0.0f);
//	to_hit[0] = MIN(to_hit[0], to_hit[1]);
//	if (isgreater(to_hit[0], 0.0f))
//		to_hit[0] = INFINITY;
//	return (INFINITY);
//}
