#include "minirt.h"



void obj_repaint(t_render *r, t_hit h)
{
	char *input_change;
	t_vec4 colors;
	
	printf("Enter the new Color in the next format: 'r g b'\n");
	input_change = read_input(100);
	char **rgba = ft_split(input_change, ' ');
	ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
	colors = ft_vec4(ft_atof(rgba[0])/255.0, ft_atof(rgba[1])/255.0, ft_atof(rgba[2])/255.0, 1.0);
	if (h.o->type == obj_sphere)
		h.o->color = colors;
	else if (h.o->type == obj_plane)
		h.o->color = colors;
	else if (h.o->type == obj_cylinder)
		h.o->color = colors;
	else if (h.o->type == obj_cone)
		h.o->color = colors;
	else
		printf(BHRED"Unsuported operation\n"END);
}

void obj_resize(t_render *r, t_hit h)
{
	char *input_change;
	float new_radius;
	
	printf("Enter the new Radius in the next format: 'r'\n");
	input_change = read_input(100);
	ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
	new_radius = ft_atof(input_change) * ft_atof(input_change);
	if (h.o->type == obj_sphere)
		h.o->obj.sp.r = new_radius;
	else if (h.o->type == obj_cylinder)
		h.o->obj.cy.r = new_radius;
	else if (h.o->type == obj_cone)
		h.o->obj.cn.r = new_radius;
	else
		printf(BHRED"Unsuported operation\n"END);
}

void obj_traslation(t_render *r, t_hit h)
{
	char *input_change;
	t_vec3 coords;
	
	printf("Enter the new Position in the next format: 'x y z'\n");
	input_change = read_input(100);
	char **xyz = ft_split(input_change, ' ');
	ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
	coords = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	if (h.o->type == obj_sphere)
		h.o->obj.sp.center = coords;
	else if (h.o->type == obj_plane)
		h.o->obj.pl.p = coords;
	else if (h.o->type == obj_cylinder)
		h.o->obj.cy.center = coords;
	else if (h.o->type == obj_cone)
		h.o->obj.cn.center = coords;
	else
		printf(BHRED"Unsuported operation\n"END);
}

void menu(t_render *r, t_ivec2 pixel)
{
	char *input_num;
	t_hit	h;

	primary_ray(&pixel, r->scene->c, &h.primary); 
	first_hit(r->scene, &h);
	if (h.o == NULL)
	{
		printf("No hit\n");
		return ;
	}
	change(&h.primary, h.o);
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