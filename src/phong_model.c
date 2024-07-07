/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:32:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/08 01:25:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_shadow(t_scene *scene, t_ray *ray)
{
	int		i;

	i = -1;
	while (scene->o[++i])
		if (isfinite(intersection(ray, scene->o[i])))
			return (1);
	return (0);
}

static t_vec4	ambient(t_ambient *a)
{
	t_vec4	c;

	return (rgba_brightness(a->color, a->ratio));
}

static void	diffuse(t_light *l, t_vec4 *n, t_ray *r, t_vec4 *c)
{
}

static void	specular(t_light *l, t_vec4 *n, t_ray *r, t_vec4 *c)
{
}

t_vec4	phong_model(t_scene *scene, t_hit *h)
{
	int		i;
	t_ray	secundary;
	t_vec4	color;

	color = ambient(scene->a);
	i = -1;
	while (scene->l[++i])
	{
		secundary_ray(&scene->l[i]->pos, &h->pos, &secundary);
		if (!in_shadow(scene, &secundary))
		{
			diffuse(scene->l[i], &h->normal, &secundary, &color);
			specular(scene->l[i], &h->normal, &secundary, &color);
		}
	}
	return (color);
}
