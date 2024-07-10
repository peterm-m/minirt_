/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:44:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 18:40:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void	log_sp(t_object *o);
static void	log_pl(t_object *o);
static void	log_cy(t_object *o);
static void	log_cn(t_object *o);

void	log_object(t_object *o)
{
	static void	(*logs[4])(t_object *) = {\
		log_sp,
		log_pl,
		log_cy,
		log_cn};

	logs[o->type](o);
	printf("rgba = (%f, %f, %f, %f)\n",
	o->color.r, o->color.g, o->color.b, o->color.a);
}

static void	log_sp(t_object *o)
{
	printf("sphere: r2 = %f; center = (%f, %f, %f); ", o->obj.sp.r,
	o->obj.sp.center.x, o->obj.sp.center.y, o->obj.sp.center.z);
}

static void	log_pl(t_object *o)
{
	printf("plane: p = (%f, %f, %f); n = (%f, %f, %f) ",
	o->obj.pl.p.x, o->obj.pl.p.y, o->obj.pl.p.z,
	o->obj.pl.normal.x, o->obj.pl.normal.y, o->obj.pl.normal.z);
}

/*
* TODO
*/

static void	log_cy(t_object *o)
{
	(void)o;
}

/*
* TODO
*/

static void	log_cn(t_object *o)
{
	(void)o;
}
