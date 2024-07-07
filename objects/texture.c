
#include "minirt.h"
#include <sys/param.h>

static t_vec2	texture_sp(t_vec3 *p, t_obj *o);
static t_vec2	texture_pl(t_vec3 *p, t_obj *o);
static t_vec2	texture_cy(t_vec3 *p, t_obj *o);
static t_vec2	texture_cn(t_vec3 *p, t_obj *o);

t_vec2	texture(t_vec3 *p, t_object *o)
{
	static t_vec2	(*textures[4])(t_vec3 *, t_obj *) = {\
		texture_sp,
		texture_pl,
		texture_cy,
		texture_cn};

	return (textures[o->type](p, &o->obj));
}

/*
* TODO
*/

static t_vec2	texture_sp(t_vec3 *p, t_obj *o)
{
	(void)p;
	(void)o;
	return (ft_vec2(1.0f, 0.0f));
}

/*
* TODO
*/

static t_vec2	texture_pl(t_vec3 *p, t_obj *o)
{
	(void)p;
	(void)o;
	return (ft_vec2(1.0f, 0.0f));
}

/*
* TODO
*/

static t_vec2	texture_cy(t_vec3 *p, t_obj *o)
{
	(void)p;
	(void)o;
	return (ft_vec2(1.0f, 0.0f));
}

/*
* TODO
*/

static t_vec2	texture_cn(t_vec3 *p, t_obj *o)
{
	(void)p;
	(void)o;
	return (ft_vec2(1.0f, 0.0f));
}
