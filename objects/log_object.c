/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:44:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 18:19:47 by pedromar         ###   ########.fr       */
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
		log_qd,
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

void	log_qd(t_object *o)
{
	printf("Quadric: 1. subtype = %d;\n" \
		"         2. a = %f, b = %f, c = %f;\n" \
		"         3. center = (%f,%f,%f);\n" \
		"         4. rotation = (%f,%f,%f);\n" \
		"         5. principal axis min = (%f,%f,%f);\n"
		"         6. principal axis max = (%f,%f,%f);\n", \
		o->obj.qd.type, \
		o->obj.qd.coef.x, o->obj.qd.coef.y, o->obj.qd.coef.z, \
		o->obj.qd.center.x, o->obj.qd.center.y, o->obj.qd.center.z, \
		o->obj.qd.angles.x, o->obj.qd.angles.y, o->obj.qd.angles.z, \
		o->obj.qd.bound_body.p_min.x, \
		o->obj.qd.bound_body.p_min.y, \
		o->obj.qd.bound_body.p_min.z, \
		o->obj.qd.bound_body.p_max.x, \
		o->obj.qd.bound_body.p_max.y, \
		o->obj.qd.bound_body.p_max.z);
}
