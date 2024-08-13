/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:12:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/08 20:27:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transform_object(t_matrix4 *m, t_object *o)
{
	static void	(*transform[6])(t_matrix4 *m, t_object *o) = {\
		transform_sp,
		transform_pl,
		transform_cy,
		transform_qd};

	transform[o->type](m, o);
	bound_object(o);
}

void	transform_sp(t_matrix4 *m, t_object *o)
{
	t_vec3	*r;

	r = &o->obj.sp.center;
	transform_vec(m, r, r);
}

void	transform_pl(t_matrix4 *m, t_object *o)
{
	t_vec3	*r;
	t_vec3	*n;

	r = &o->obj.pl.p;
	n = &o->obj.pl.normal;
	transform_vec(m, r, r);
	transform_dir(m, n, n);
	o->obj.pl.n_dot_p = ft_dotv3(o->obj.pl.p, o->obj.pl.normal);
}

void	transform_cy(t_matrix4 *m, t_object *o)
{
	t_vec3	*r;
	t_vec3	*n;

	r = &o->obj.cy.center;
	n = &o->obj.cy.normal;
	transform_vec(m, r, r);
	transform_dir(m, n, n);
}

/*
* TODO
*/

void	transform_qd(t_matrix4 *m, t_object *o)
{
	(void)o;
	(void)m;
	return ;
}
