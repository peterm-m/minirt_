
#include "minirt.h"

static void	primary_ray(t_ivec2 *pixel, t_camera *c, t_ray *ray)
{
	t_vec2	pixel_ndc;
	t_vec2	pixel_screen;
	t_vec3	dir;

	pixel_ndc.x = (pixel->x + 0.5f) / WIN1_SX;
	pixel_ndc.y = (pixel->y + 0.5f) / WIN1_SY;
	pixel_screen.x = (2.0f * pixel_ndc.x - 1.0f);
	pixel_screen.y = 1.0f - 2.0f * pixel_ndc.y;
	dir.x = pixel_screen.x * WIN1_SX / WIN1_SY * c->fov;
	dir.y = pixel_screen.y ;
	dir.z = -1.0f;
	applay_transformation(&c->cam_world, &dir, &ray->d);
	ray->d = ft_normv3(ray->d);
	ray->o = c->pos;
}

static void	render_trace(t_scene *scene, t_ray *ray, t_hit *hit)
{
	float	aux;
	int		i;

	hit->o = NULL;
	hit->to_hit = INFINITY;
	i = -1;
	while (scene->o[++i])
	{
		aux = intersection(ray, scene->o[i]);
		if (isless(aux, hit->to_hit))
		{
			hit->to_hit = aux;
			hit->o = scene->o[i];
		}
	}
}

int	phong_model(t_scene *scene, t_hit *h)
{
	t_vec4	color;

	color = ft_mulv4f();
	return (set_rgba(h->o->color));
}

int	render_loop(t_render *r)
{
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
				surface_info(&primary, &h);
				put_pixel(r->canvas, &pixel, phong_model(r->scene, &h));
			}
		}
	}
	canvas_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
