#include "minirt.h"

static void	change_cy(t_object *o);
static void	change_cn(t_object *o);
static void	change_pl(t_object *o);
static void	change_sp(t_object *o);

void	change(t_object *obj)
{
	static void	(*changes[4])(t_object *) = {\
		change_sp,
		change_pl,
		change_cy,
		change_cn};

	changes[obj->type](r, obj);
}

static void	change_pl(t_object *o)
{
	printf(BHMAG"YOU SELECTED OBJECT: "BHCYN"plane "END);
    printf(BHMAG"with the next attributes:\n");
    printf(BHMAG"- Radius: "BHCYN"%f\n"END BHMAG"- Center coordenates: "BHCYN
    "(%f, %f, %f)\n"END, sqrt(o->obj.pl.r),o->obj.pl.center.x, o->obj.pl.center.y, o->obj.pl.center.z);
    printf(BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n",
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f), o->color.a);
	printf(BHMAG"Select which attribute you want to change:\n"END);
	printf(BHRED"1. Position\n"BHGRN"2. Normal\n"BHBLU"3. Color\n"END);
    input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		obj_traslation(r, h);
	else if (ft_strncmp(input_num, "2", 1) == 0)
		obj_normal(r, h);//TODO
	else if (ft_strncmp(input_num, "3", 1) == 0)
		obj_repaint(r, h);
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
}

static void	change_sp(t_object *o)
{
	printf(BHMAG"YOU SELECTED OBJECT: "BHCYN"sphere "END);
    printf(BHMAG"with the next attributes:\n");
    printf(BHMAG"- Radius: "BHCYN"%f\n"END BHMAG"- Center coordenates: "BHCYN
    "(%f, %f, %f)\n"END, sqrt(o->obj.sp.r),o->obj.sp.center.x, o->obj.sp.center.y, o->obj.sp.center.z);
    printf(BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n",
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f), o->color.a);
	printf(BHMAG"Select which attribute you want to change:\n"END);
	printf(BHRED"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Color\n"END);
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

static void	change_cy(t_object *o)
{
	printf(BHMAG"YOU SELECTED OBJECT: "BHCYN"cylinder "END);
    printf(BHMAG"with the next attributes:\n");
    printf(BHMAG"- Radius: "BHCYN"%f\n"END BHMAG"- Center coordenates: "BHCYN
    "(%f, %f, %f)\n"END, sqrt(o->obj.cy.r),o->obj.cy.center.x, o->obj.cy.center.y, o->obj.cy.center.z);
    printf(BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n",
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f), o->color.a);
	printf(BHMAG"Select which attribute you want to change:\n"END);
	printf(BHRED"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Color\n"BHYEL"4. Height"BHMAG"5. Normal\n"END);
    input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		obj_traslation(r, h);
	else if (ft_strncmp(input_num, "2", 1) == 0)
		obj_resize(r, h);
	else if (ft_strncmp(input_num, "3", 1) == 0)
		obj_repaint(r, h);
    else if (ft_strncmp(input_num, "4", 1) == 0)
		obj_resize_h(r, h);//TODO
    else if (ft_strncmp(input_num, "5", 1) == 0)
		obj_normal(r, h);
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
}


static void	change_cn(t_object *o)
{
	printf(BHMAG"YOU SELECTED OBJECT: "BHCYN"cone "END);
    printf(BHMAG"with the next attributes:\n");
    printf(BHMAG"- Radius: "BHCYN"%f\n"END BHMAG"- Center coordenates: "BHCYN
    "(%f, %f, %f)\n"END, sqrt(o->obj.cn.r),o->obj.cn.center.x, o->obj.cn.center.y, o->obj.cn.center.z);
    printf(BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n",
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f), o->color.a);
	printf(BHMAG"Select which attribute you want to change:\n"END);
	printf(BHRED"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Color\n"BHYEL"4. Height"BHMAG"5. Normal\n"END);
    input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		obj_traslation(r, h);
	else if (ft_strncmp(input_num, "2", 1) == 0)
		obj_resize(r, h);
	else if (ft_strncmp(input_num, "3", 1) == 0)
		obj_repaint(r, h);
    else if (ft_strncmp(input_num, "4", 1) == 0)
		obj_resize_h(r, h);//TODO
    else if (ft_strncmp(input_num, "5", 1) == 0)
		obj_normal(r, h);
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
}