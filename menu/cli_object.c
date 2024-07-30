/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:52 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/30 19:53:03 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cli_object(t_object *o)
{
	static void	(*clis[4])(t_object *) = {\
		cli_sp,
		cli_pl,
		cli_cy,
		cli_qd
        };

	clis[o->type](o);
}

void	cli_sp(t_object *o)
{
	printf(BHYEL"SPHERE "BHMAG"with the next attributes:\n- Radius: "BHCYN"%f\n"
	BHMAG"- Center coordenates: "BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgb: "BHCYN
	"(%f, %f, %f)\n"BHMAG"Select which attribute you want to change:\n\n"
	BHRED"0. Exit\n"BHWHT"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Material\n"
	BHBLK"4. Ambient\n\n"END, sqrt(o->obj.sp.r2), o->obj.sp.center.x,
	o->obj.sp.center.y, o->obj.sp.center.z, rint(o->material.k_d.r * 255.0f),
	rint(o->material.k_d.g * 255.0f), rint(o->material.k_d.b * 255.0f));
}

void	cli_pl(t_object *o)
{
	printf(BHYEL"PLANE "BHMAG"with the next attributes:\n"
	"- Center coordenates: "BHCYN"(%f, %f, %f)\n" BHMAG"- Normal:"BHCYN
	"(%f, %f, %f)\n"BHMAG"- Color rgb: "BHCYN"(%f, %f, %f)\n"BHMAG
	"Select which attribute you want to change:\n\n"BHRED"0. Exit\n"BHWHT
    "1. Position\n"BHGRN"2. Normal\n"BHBLU"3. Material\n"BHBLK"4. Ambient\n\n"
	END,o->obj.pl.p.elements[0], o->obj.pl.p.elements[1],
	o->obj.pl.p.elements[2], o->obj.pl.normal.elements[0],
	o->obj.pl.normal.elements[1], o->obj.pl.normal.elements[2], 
	rint(o->material.k_d.r * 255.0f), rint(o->material.k_d.g * 255.0f),
	rint(o->material.k_d.b * 255.0f));
}

void	cli_cy(t_object *o)
{
	printf(BHYEL"CYLINDER "BHMAG
	"with the next attributes:\n- Radius: "BHCYN"%f\n"BHMAG
	"- Center coordenates: "BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgb: "BHCYN
	"(%f, %f, %f)\n"BHMAG"- Height: "BHCYN"%f\n"BHMAG"Normal: "BHCYN
	"(%f, %f, %f)\n"BHMAG"Select which attribute you want to change:\n\n"BHRED
	"0. Exit\n"BHWHT"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Material\n"BHBLK
	"4. Ambient\n"BHYEL"5. Height\n"BHMAG"6. Normal\n\n"END, sqrt(o->obj.cy.r2),
	o->obj.cy.center.x, o->obj.cy.center.y, o->obj.cy.center.z,
	rint(o->material.k_d.r * 255.0f), rint(o->material.k_d.g * 255.0f),
	rint(o->material.k_d.b * 255.0f), o->obj.cy.h, o->obj.cy.normal.x,
	o->obj.cy.normal.y, o->obj.cy.normal.z);
}

void	cli_qd(t_object *o)
{
    (void)o;
	printf(BHYEL" QUADRATIC "BHMAG);
}