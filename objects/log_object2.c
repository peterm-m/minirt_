/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:44:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/26 18:58:14 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "colors.h"

void	log_disk(t_object *o)
{
	printf("disk: 1. center = (%f, %f, %f);\n" \
		"         2. normal = (%f, %f, %f);\n" \
		"         3. r2 = %f;\n", \
		o->obj.disk.center.x, o->obj.disk.center.y, o->obj.disk.center.z, \
		o->obj.disk.normal.x, o->obj.disk.normal.y, o->obj.disk.normal.z, \
		o->obj.disk.r2);
}

void	log_tr(t_object *o)
{
	printf("triangle: 1. v0 = (%f, %f, %f);\n" \
		"             2. v1 = (%f, %f, %f);\n" \
		"             3. v2 = (%f, %f, %f);\n" \
		"             4. n = (%f, %f, %f);\n", \
		o->obj.tr.v0.x, o->obj.tr.v0.y, o->obj.tr.v0.z, \
		o->obj.tr.v1.x, o->obj.tr.v1.y, o->obj.tr.v1.z, \
		o->obj.tr.v2.x, o->obj.tr.v2.y, o->obj.tr.v2.z, \
		o->obj.tr.n.x, o->obj.tr.n.y, o->obj.tr.n.z);
}
