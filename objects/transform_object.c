/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:12:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 13:17:10 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transform_object(t_hit *h)
{
	static void	(*transform[6])(t_hit *h) = {\
		transform_sp,
		transform_pl,
		transform_cy,
		transform_cn,
		transform_disk,
		transform_tr};

	transform[h->o->type](h);
}

/*
* TODO
*/

void	transform_sp(t_object *h)
{
	(void)h;
	return ;
}

/*
* TODO
*/

void	transform_pl(t_object *h)
{
	(void)h;
	return ;
}

/*
* TODO
*/

void	transform_cy(t_object *h)
{
	(void)h;
	return ;
}

/*
* TODO
*/

void	transform_cn(t_object *h)
{
	(void)h;
	return ;
}
