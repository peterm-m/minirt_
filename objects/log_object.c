/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:44:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/26 10:40:05 by adiaz-uf         ###   ########.fr       */
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
}

void	log_sp(t_object *o)
{
	printf(BHYEL"SPHERE "BHMAG"with the next attributes:\n- Radius: "BHCYN"%f\n"
	BHMAG"- Center coordenates: "BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN
	"(%f, %f, %f, %f)\n"BHMAG"Select which attribute you want to change:\n\n"
	BHRED"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Color\n\n"END, 
	sqrt(o->obj.sp.r2), o->obj.sp.center.x, o->obj.sp.center.y, 
	o->obj.sp.center.z, rint(o->color.r * 255.0f), rint(o->color.g * 255.0f),
	rint(o->color.b * 255.0f), o->color.a);
}

void	log_pl(t_object *o)
{
	printf(BHYEL"PLANE "BHMAG"with the next attributes:\n"
	"- Center coordenates: "BHCYN"(%f, %f, %f)\n" BHMAG"- Normal:"BHCYN
	"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n"BHMAG
	"Select which attribute you want to change:\n\n"BHRED"1. Position\n"BHGRN
	"2. Normal\n"BHBLU"3. Color\n\n"END,o->obj.pl.p.elements[0],
	o->obj.pl.p.elements[1], o->obj.pl.p.elements[2], o->obj.pl.normal.elements[0],
	o->obj.pl.normal.elements[1], o->obj.pl.normal.elements[2],
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f),
	o->color.a);
}

void	log_cy(t_object *o)
{
	printf(BHYEL"CYLINDER "BHMAG
	"with the next attributes:\n- Radius: "BHCYN"%f\n"BHMAG"- Center coordenates: "
	BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n"BHMAG
	"- Height: "BHCYN"%f\n"BHMAG"Normal: "BHCYN"(%f, %f, %f)\n"BHMAG
	"Select which attribute you want to change:\n\n"BHRED"1. Position\n"BHGRN
	"2. Radius\n"BHBLU"3. Color\n"BHYEL"4. Height\n"BHMAG"5. Normal\n"END, 
	sqrt(o->obj.cy.r2), o->obj.cy.center.x, o->obj.cy.center.y, o->obj.cy.center.z,
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f),
	o->color.a, o->obj.cy.h, o->obj.cy.normal.x, o->obj.cy.normal.y, o->obj.cy.normal.z);
}

void	log_cn(t_object *o)
{
	printf(BHYEL"CONE "BHMAG
	"with the next attributes:\n- Radius: "BHCYN"%f\n"BHMAG"- Center coordenates: "
	BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n"BHMAG
	"- Height: "BHCYN"%f\n"BHMAG"Normal: "BHCYN"(%f, %f, %f)\n"BHMAG
	"Select which attribute you want to change:\n\n"BHRED"1. Position\n"BHGRN
	"2. Radius\n"BHBLU"3. Color\n"BHYEL"4. Height\n"BHMAG"5. Normal\n"END, 
	sqrt(o->obj.cn.rb), o->obj.cn.center.x, o->obj.cn.center.y, o->obj.cn.center.z,
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f),
	o->color.a, o->obj.cn.h, o->obj.cn.normal.x, o->obj.cn.normal.y, o->obj.cn.normal.z);
}
