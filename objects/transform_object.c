/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:12:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 18:21:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transform_object(t_matrix4 *m, t_object *o)
{
	static void	(*transform[6])(t_matrix4 *m, t_object *o) = {\
		transform_sp,
		transform_pl,
		transform_cy,
		transform_qd,
		transform_disk,
		transform_tr};

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
