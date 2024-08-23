/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:12:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/23 17:28:20 by pedromar         ###   ########.fr       */
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

void	transform_qd(t_matrix4 *m, t_object *o)
{
	t_vec3		*r;
	t_matrix4	w2obj;

	r = &o->obj.qd.center;
	transform_vec(m, r, r);
	o->obj.qd.a = ft_mat4();
	o->obj.qd.a.elements[0][0] = o->obj.qd.coef.x;
	o->obj.qd.a.elements[2][2] = o->obj.qd.coef.z;
	o->obj.qd.a.elements[1][1] = o->obj.qd.coef.y * (o->obj.qd.type != 3);
	o->obj.qd.a.elements[1][3] = \
		o->obj.qd.coef.y / 2.0f * (o->obj.qd.type == 3);
	o->obj.qd.a.elements[3][1] = o->obj.qd.a.elements[1][3];
	o->obj.qd.a.elements[3][3] = (o->obj.qd.type == 0) - (o->obj.qd.type == 2);
	w2obj = get_invtransform(o->obj.qd.center, \
		o->obj.qd.angles, ft_vec3(1, 1, 1));
	o->obj.qd.a = ft_mulm4m(w2obj, ft_mulm4m(o->obj.qd.a, \
		ft_transposem4(w2obj)));
	return ;
}
