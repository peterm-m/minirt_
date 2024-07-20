/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:44:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:30:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "colors.h"

void	log_disk(t_object *o)
{
	printf("disk: center = (%f, %f, %f);\n" \
		"         normal = (%f, %f, %f);\n" \
		"         r2 = %f;\n", \
		o->obj.disk.center.x, o->obj.disk.center.y, o->obj.disk.center.z, \
		o->obj.disk.normal.x, o->obj.disk.normal.y, o->obj.disk.normal.z, \
		o->obj.disk.r2);
}

void	log_tr(t_object *o)
{
	printf("triangle: v0 = (%f, %f, %f);\n" \
		"             v1 = (%f, %f, %f);\n" \
		"             v2 = (%f, %f, %f);\n", \
		o->obj.tr.v0.x, o->obj.tr.v0.y, o->obj.tr.v0.z, \
		o->obj.tr.v1.x, o->obj.tr.v1.y, o->obj.tr.v1.z, \
		o->obj.tr.v2.x, o->obj.tr.v2.y, o->obj.tr.v2.z);
}
