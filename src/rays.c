
#include "minirt.h"

void	primary_ray(t_ivec2 *pixel, t_camera *c, t_ray *ray)
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

void	secundary_ray(t_vec3 *from, t_vec3 *to, t_ray *ray)
{
	ray->d = ft_normv3(ft_subv3(*from, *to));
	ray->o = *from;
}
