
#include "minirt.h"

static t_vec3	normal_sp(t_vec3 *p, t_obj *o);
static t_vec3	normal_pl(t_vec3 *p, t_obj *o);
static t_vec3	normal_cy(t_vec3 *p, t_obj *o);
static t_vec3	normal_cn(t_vec3 *p, t_obj *o);

t_vec3	normal(t_vec3 *p, t_object *obj)
{
	static t_vec3	(*normals[4])(t_vec3 *, t_obj *) = {\
		normal_sp,
		normal_pl,
		normal_cy,
		normal_cn};

	return (normals[obj->type](p, &obj->obj));
}

static t_vec3	normal_sp(t_vec3 *p, t_obj *o)
{
	t_vec3	v;

	v = ft_subv3(*p, o->sp.center);
	return (ft_divv3f(v, ft_lenv3(v)));
}

static t_vec3	normal_pl(t_vec3 *p, t_obj *o)
{
	(void) p;
	return (o->pl.normal);
}

/*
* TODO
*/

static t_vec3	normal_cy(t_vec3 *p, t_obj *o)
{
	(void)p;
	(void)o;
	return (ft_vec3(1.0f, 0.0f, 0.0f));
}

/*
* TODO
*/

static t_vec3	normal_cn(t_vec3 *p, t_obj *o)
{
	(void)p;
	(void)o;
	return (ft_vec3(1.0f, 0.0f, 0.0f));
}
