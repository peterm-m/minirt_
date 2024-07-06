
#include "minirt.h"

static void	primary_ray(t_ivec2 *pixel, t_camera *c, t_ray *ray)
{
	t_vec2	pixel_ndc;
	t_vec2	pixel_screen;
	t_vec3	dir;

	pixel_ndc.x = (pixel->x + 0.5f) / WIN1_SX ;
	pixel_ndc.y = (pixel->y + 0.5f) / WIN1_SY;
	pixel_screen.x = (2.0f * pixel_ndc.x - 1.0f) ;
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
	int	i;

	hit->pl = NULL;
	hit->to_hit = INFINITY;
	i = -1;
	while (scene->pl[++i])
	{
		aux = intersection_pl(ray, scene->pl[i]);
		if (isless(aux, hit->to_hit))
		{
			hit->to_hit = aux;
			hit->pl = scene->pl[i];
		}
	}
}

int	phong_model(t_scene *scene, t_hit *hit)
{
	t_hit	h;
	t_ray	to_light;
	t_vec4	color;

	h.pl = NULL;
	h.to_hit = INFINITY;
	to_light.o = hit->normal;
	to_light.d = ft_subv3(hit->pos, scene->l[0]->pos);
	to_light.d = ft_normv3(to_light.d);
	render_trace(scene, &to_light, &h);
	return (set_rgba(scene->pl[0]->color));
}

int	render_loop(t_render *r)
{
	t_ray	primary;
	t_ivec2	pixel;
	t_hit	hit;

	pixel.x = -1;
	while (++pixel.x < WIN1_SX)
	{
		pixel.y = -1;
		while (++pixel.y < WIN1_SY)
		{
			primary_ray(&pixel, r->scene->c, &primary);
			render_trace(r->scene, &primary, &hit);
			if (hit.pl != NULL)
			{
				hit.pos = ft_addv3(ft_mulv3f(primary.d, hit.to_hit), primary.o);
				hit.normal = normal_pl(&hit.pos, hit.pl);
				put_pixel(r->canvas, &pixel, phong_model(r->scene, &hit));
			}
		}
	}
	canvas_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
