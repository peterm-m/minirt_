/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:44:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/24 12:21:47 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "colors.h"

void	log_object(t_object *o)
{
	static void	(*logs[6])(t_object *) = {\
		log_sp,
		log_pl,
		log_cy,
		log_cn,
		log_disk,
		log_tr};

	logs[o->type](o);
	printf(BHMAG"Color rgba: "BHCYN"(%f, %f, %f, %f)\n",
		o->color.r, o->color.g, o->color.b, o->color.a);
}

void	log_sp(t_object *o)
{
	printf("Sphere: 1. radius2 = %f\n" \
		"        2. center = (%f, %f, %f)\n", \
		o->obj.sp.r2,
		o->obj.sp.center.x, o->obj.sp.center.y, o->obj.sp.center.z);
}

void	log_pl(t_object *o)
{
	printf("plane: 1. p = (%f, %f, %f);\n" \
		"       2. n = (%f, %f, %f)\n",
		o->obj.pl.p.x, o->obj.pl.p.y, o->obj.pl.p.z,
		o->obj.pl.normal.x, o->obj.pl.normal.y, o->obj.pl.normal.z);
}

void	log_cy(t_object *o)
{
	printf("cylinder: 1. center = (%f, %f, %f);\n" \
		"          2. normal = (%f, %f, %f);\n" \
		"          3. r2 = %f;\n" \
		"          3. h = %f;\n", \
		o->obj.cy.center.x, o->obj.cy.center.y, o->obj.cy.center.z, \
		o->obj.cy.normal.x, o->obj.cy.normal.y, o->obj.cy.normal.z, \
		o->obj.cy.r2, o->obj.cy.h);
}

void	log_cn(t_object *o)
{
	printf("cone: center = (%f, %f, %f);\n" \
		"      normal = (%f, %f, %f);\n" \
		"      ra = %f;\n" \
		"      rb = %f;\n" \
		"      h = %f;\n", \
		o->obj.cn.center.x, o->obj.cn.center.y, o->obj.cn.center.z, \
		o->obj.cn.normal.x, o->obj.cn.normal.y, o->obj.cn.normal.z, \
		o->obj.cn.ra, o->obj.cn.rb, o->obj.cn.h);
}
