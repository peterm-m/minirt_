/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:12:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/07 12:05:59 by pedromar         ###   ########.fr       */
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
}

/*
* TODO
*/

void	transform_sp(t_matrix4 *m, t_object *o)
{
	(void)o;
	(void)m;
	return ;
}

/*
* TODO
*/

void	transform_pl(t_matrix4 *m, t_object *o)
{
	(void)o;
	(void)m;
	return ;
}

/*
* TODO
*/

void	transform_cy(t_matrix4 *m, t_object *o)
{
	(void)o;
	(void)m;
	return ;
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
