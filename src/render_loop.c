
#include "minirt.h"

void	render_trace(t_scene *scene, t_ray *ray, t_hit *hit)
{
	float	aux;
	int		i;

	hit->o = NULL;
	hit->to_hit = INFINITY;
	i = -1;
	while (scene->o[++i])
	{
		aux = intersection(ray, scene->o[i]);
		if (isfinite(aux) && isless(aux, hit->to_hit))
		{
			hit->to_hit = aux;
			hit->o = scene->o[i];
		}
	}
}

int	render_loop(t_render *r)
{
	int	si_hit = 0;
	int no_hit = 0;
	t_ray	primary;
	t_ivec2	pixel;
	t_hit	h;

	pixel.x = -1;
	while (++pixel.x < WIN1_SX)
	{
		pixel.y = -1;
		while (++pixel.y < WIN1_SY)
		{
			primary_ray(&pixel, r->scene->c, &primary);
			render_trace(r->scene, &primary, &h);
			if (h.o != NULL)
			{
				si_hit++;
				surface_info(&primary, &h);
				put_pixel(r->canvas, &pixel, rgba_to_int(phong_model(r->scene, &h)));
			}
			else
				no_hit++;
		}
	}
	printf("%s:%d si %d no %d\n", __FILE__, __LINE__, si_hit, no_hit);
	canvas_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
