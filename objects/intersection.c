
#include "minirt.h"
#include <sys/param.h>

static float	intersection_cy(t_ray *r, t_obj *o);
static float	intersection_cn(t_ray *r, t_obj *o);
static float	intersection_pl(t_ray *r, t_obj *o);
static float	intersection_sp(t_ray *r, t_obj *o);

float	intersection(t_ray *r, t_object *obj)
{
	static float	(*intersections[4])(t_ray *, t_obj *) = {\
		intersection_sp,
		intersection_pl,
		intersection_cy,
		intersection_cn};

	return (intersections[obj->type](r, &obj->obj));
}

/*
* TODO: podemos añadir a la estructura plano el producto 
*		np = ft_dotv3(pl->normal, pl->p);
* para no tener que calcularlo.
*/

static float	intersection_pl(t_ray *r, t_obj *o)
{
	float	to_hit;
	float	nd;
	float	no;
	float	np;

	to_hit = INFINITY;
	nd = ft_dotv3(r->d, o->pl.normal);
	if (isless(nd, 0.0f))
		return (to_hit);
	no = ft_dotv3(r->o, o->pl.normal);
	np = ft_dotv3(o->pl.normal, o->pl.p);
	to_hit = MAX(np - no / nd, 0.0f);
	if (isless(to_hit, 0.0f))
		to_hit = INFINITY;
	return (to_hit);
}

/*
* TODO: podemos guardar r^2 para evitar calcularlo en sp
*/

static float	intersection_sp(t_ray *r, t_obj *o)
{
	t_vec3	m;
	float	b;
	float	c;
	float	discriminant;
	float	to_hit;

	to_hit = INFINITY;
	m = ft_subv3(r->o, o->sp.center);
	b = ft_dotv3(m, r->d);
	c = ft_lensqrv3(m) - o->sp.r * o->sp.r;
	if (isgreater(c, 0.0f) && isgreater(b, 0.0f))
		return (to_hit);
	discriminant = b * b - c;
	if (isless(discriminant, 0.0f))
		return (to_hit);
	to_hit = -b - sqrt(discriminant);
	if (islessequal(to_hit, 0.0f))
		to_hit = INFINITY;
	return (to_hit);
}

/*
* TODO
*/

static float	intersection_cy(t_ray *r, t_obj *o)
{
	(void)r;
	(void)o;
	return (INFINITY);
}

/*
* TODO
*/

static float	intersection_cn(t_ray *r, t_obj *o)
{
	(void)r;
	(void)o;
	return (INFINITY);
}
