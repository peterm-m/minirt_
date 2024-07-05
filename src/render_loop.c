
#include "minirt.h"

static t_hit	render_trace(t_scene *scene, int x, int y)
{
	t_ray	r;
	t_hit	hit;
	float	aux;
	int	i;

	hit.sp = NULL;
	hit.to_hit = INFINITY;
	i = -1;
	while (scene->sp[++i])
	{
		aux = intersection_sp(&r, scene->sp[i]);
		if (isless(hit.to_hit, aux))
		{
			hit.to_hit = aux;
			hit.sp = scene->sp[i];
		}
	}
//	i = -1;
//	while (scene->pl[++i])
//		if ()
//		; // check intersection plane
//		i = -1;
//	while (scene->cy[++i])
//		if ()
//		; // check intersection cylinder
	return (hit);
}

int	render_loop(t_render *r)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN1_SX)
	{
		y = -1;
		while (++y < WIN1_SY)
		{
			render_trace(r->scene, x, y);
		}
	}
	canvas_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
