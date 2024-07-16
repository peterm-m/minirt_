#include "minirt.h"

static void	change_cy(t_ray *r, t_object *o);
static void	change_cn(t_ray *r, t_object *o);
static void	change_pl(t_ray *r, t_object *o);
static void	change_sp(t_ray *r, t_object *o);

void	change(t_ray *r, t_object *obj)
{
	static void	(*changes[4])(t_ray *, t_object *) = {\
		change_sp,
		change_pl,
		change_cy,
		change_cn};

	changes[obj->type](r, obj);
}

static void	change_pl(t_ray *r, t_object *o)
{
    (void)r;
    (void)o;
}

static void	change_sp(t_ray *r, t_object *o)
{
    (void)r;
    printf(BHBLU"\n-------------------------------------------------------\n\n"END);
	printf(BHMAG"YOU SELECTED OBJECT: "BHCYN"sphere "END);
    printf(BHMAG"with the next attributes:\n");
    printf(BHMAG"- Radius: "BHCYN"%f\n"END BHMAG"- Center coordenates: "BHCYN
    "(%f, %f, %f)\n"END, sqrt(o->obj.sp.r),o->obj.sp.center.x, o->obj.sp.center.y, o->obj.sp.center.z);
    printf(BHMAG"- Color rgba: "BHCYN"(%f, %f, %f, %f)\n",
	rint(o->color.r * 255.0f), rint(o->color.g * 255.0f), rint(o->color.b * 255.0f), o->color.a);
	printf(BHMAG"Select which attribute you want to change:\n"END);
	printf(BHRED"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Color\n");
	printf("\n-------------------------------------------------------\n"END);
}

static void	change_cy(t_ray *r, t_object *o)
{
    (void)r;
    (void)o;
}


static void	change_cn(t_ray *r, t_object *o)
{
    (void)r;
    (void)o;
}