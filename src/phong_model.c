
#include "minirt.h"

static float	diffuse_term(t_object **o, t_ray *ray, t_vec3 *n)
{
	float	diffuse_reflected;
	int		i;

	i = -1;
	while (o[++i])
		if (isfinite(intersection(ray, o[i])))
			return (0.0f);
	diffuse_reflected = ft_dotv3(ray->d, *n);
	return (MAX(diffuse_reflected, 0.0f));
}

static float	specular_term(t_light *l, t_vec3 *n, t_ray *ray, t_vec3 *p)
{
	float	specular;
	t_vec3	r;
	t_vec3	v;

	r = ft_subv3(ft_mulv3f(*n, 2.0f * ft_dotv3(ray->d, *n)), ray->d);
	v = ft_normv3(ft_mulv3f(*p, -1.0f));
	specular = ft_dotv3(r, v);
	return (pow(MAX(specular, 0.0f), 50.0f));
}

t_vec4	phong_model(t_scene *scene, t_hit *h)
{
	int		i;
	t_ray	secundary;
	float	diffuse;
	float	specular;
	t_vec4	color;

	color = rgba_brightness(scene->a->color, scene->a->ratio);
	i = -1;
	while (scene->l[++i])
	{
		secundary_ray(&scene->l[i]->pos, &h->pos, &secundary);
		diffuse = diffuse_term(scene->o, &secundary, &h->normal);
		specular = 0.0f; 
		if (isgreater(diffuse, 0.0f))
			specular = specular_term(scene->l[i], &h->normal, &secundary, &h->pos);
		color = rgba_sum(color, rgba_brightness(scene->l[i]->color, scene->l[i]->ratio * diffuse));
		color = rgba_sum(color, rgba_brightness(scene->l[i]->color, 0.6f * scene->l[i]->ratio * specular));
	}
	return (ft_mulv4v(h->o->color, color));
}
