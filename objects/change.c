/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:25:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/24 11:56:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	change_cy(t_render *r, t_hit h);
static void	change_cn(t_render *r, t_hit h);
static void	change_pl(t_render *r, t_hit h);
static void	change_sp(t_render *r, t_hit h);

void	change(t_render *r, t_object *obj, t_hit h)
{
	static char	*names[4] = {"sphere", "plane", "cylinder", "con./m	e"};
	static void	(*changes[4])(t_render *r, t_hit h) = {\
		change_sp,
		change_pl,
		change_cy,
		change_cn};

	printf(BHMAG"\n\nSELECTED OBJECT: "BHYEL"%s"BHMAG":\n", names[obj->type]);
	log_object(obj);
	changes[obj->type](r, h);
}

static void	change_pl(t_render *r, t_hit h)
{return ;
	char *input_num;

	//printf("- Center coordenates: "BHCYN"(%f, %f, %f)\n" BHMAG"- Normal:"BHCYN
	//"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n"BHMAG
	//"Select which attribute you want to change:\n\n"BHRED"1. Position\n"BHGRN
	//"2. Normal\n"BHBLU"3. Color\n\n"END,o->obj.pl.p.elements[0],
	//o->obj.pl.p.elements[1], o->obj.pl.p.elements[2], o->obj.pl.normal.elements[0],
	//o->obj.pl.normal.elements[1], o->obj.pl.normal.elements[2],
	//rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f),
	//o->color.a);
    input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		obj_traslation(r, h);
	else if (ft_strncmp(input_num, "2", 1) == 0)
		obj_normal(r, h);
	else if (ft_strncmp(input_num, "3", 1) == 0)
		obj_repaint(r, h);
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
}

static void	change_sp(t_render *r, t_hit h)
{return ;
	char *input_num;

	//printf("- Radius: "BHCYN"%f\n"BHMAG
	//"- Center coordenates: "BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN
	//"(%f, %f, %f, %f)\n"BHMAG"Select which attribute you want to change:\n\n"BHRED
	//"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Color\n\n"END, sqrt(o->obj.sp.r),
	//o->obj.sp.center.x, o->obj.sp.center.y, o->obj.sp.center.z,
	//rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f),
	//o->color.a);
	input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		obj_traslation(r, h);
	else if (ft_strncmp(input_num, "2", 1) == 0)
		obj_resize(r, h);
	else if (ft_strncmp(input_num, "3", 1) == 0)
		obj_repaint(r, h);
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
}

static void	change_cy(t_render *r, t_hit h)
{return ;
	char *input_num;

	//printf("- Radius: "BHCYN"%f\n"BHMAG"- Center coordenates: "
	//BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n"BHMAG
	//"Select which attribute you want to change:\n\n"BHRED"1. Position\n"BHGRN
	//"2. Radius\n"BHBLU"3. Color\n"BHYEL"4. Height\n"BHMAG"5. Normal\n"END, 
	//sqrt(o->obj.cy.r), o->obj.cy.center.x, o->obj.cy.center.y, o->obj.cy.center.z,
	//rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f),
	//o->color.a);
    input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		obj_traslation(r, h);
	else if (ft_strncmp(input_num, "2", 1) == 0)
		obj_resize(r, h);
	else if (ft_strncmp(input_num, "3", 1) == 0)
		obj_repaint(r, h);
    else if (ft_strncmp(input_num, "4", 1) == 0)
		obj_resize_h(r, h);
    else if (ft_strncmp(input_num, "5", 1) == 0)
		obj_normal(r, h);
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
}


static void	change_cn(t_render *r, t_hit h)
{return ;
	char *input_num;

	//printf("- Radius: "BHCYN"%f\n"BHMAG"- Center coordenates: "
	//BHCYN"(%f, %f, %f)\n"BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n"BHMAG
	//"Select which attribute you want to change:\n\n"BHRED"1. Position\n"BHGRN
	//"2. Radius\n"BHBLU"3. Color\n"BHYEL"4. Height\n"BHMAG"5. Normal\n"END, 
	//sqrt(o->obj.cn.r), o->obj.cn.center.x, o->obj.cn.center.y, o->obj.cn.center.z,
	//rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f),
	//o->color.a);
	input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		obj_traslation(r, h);
	else if (ft_strncmp(input_num, "2", 1) == 0)
		obj_resize(r, h);
	else if (ft_strncmp(input_num, "3", 1) == 0)
		obj_repaint(r, h);
    else if (ft_strncmp(input_num, "4", 1) == 0)
		obj_resize_h(r, h);
    else if (ft_strncmp(input_num, "5", 1) == 0)
		obj_normal(r, h);
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
}
