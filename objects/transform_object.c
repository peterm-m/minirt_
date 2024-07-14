/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:11:55 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/12 17:26:14 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void	transform_sp(t_matrix4 *m, t_object *o);
static void	transform_pl(t_matrix4 *m, t_object *o);
static void	transform_cy(t_matrix4 *m, t_object *o);
static void	transform_cn(t_matrix4 *m, t_object *o);

void	transform_object(t_matrix4 *m, t_object *o)
{
	static void	(*transforms[4])(t_matrix4 *, t_object *) = {\
		transform_sp,
		transform_pl,
		transform_cy,
		transform_cn};

	transforms[o->type](m, o);
}

static void	transform_sp(t_matrix4 *m, t_object *o)
{
	applay_transformation(m, &o->obj.sp.center, &o->obj.sp.center);
}

static void	transform_pl(t_matrix4 *m, t_object *o)
{
	(void)m;
	(void)o;
}

static void	transform_cy(t_matrix4 *m, t_object *o)
{
	(void)m;
	(void)o;
}

static void	transform_cn(t_matrix4 *m, t_object *o)
{
	(void)m;
	(void)o;
}
