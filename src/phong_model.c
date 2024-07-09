/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:32:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 22:58:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*in_shadow(t_scene *scene, t_hit *h)
{
	int		i;

	i = 0;
	while (scene->o[i] && !isfinite(intersection(&h->secundary, scene->o[i])))
		i++;
	return (scene->o[i]);
}

static void	add_illumination(t_light *l, t_hit *h, t_vec4 *color)
{
	float	diff_factor;
	float	spec_factor;

	diff_factor = ft_dotv3(h->secundary.d, h->normal);
	if (islessequal(diff_factor, 0.0f))
		return ;
	spec_factor = -2.0f * diff_factor * ft_dotv3(h->primary.d, h->normal)
		+ ft_dotv3(h->primary.d, h->secundary.d);
	spec_factor = pow(MAX(spec_factor, 0.0f), 50.0f);
	rgba_sum(color, l->color, diff_factor);
	rgba_sum(color, l->color, 0.6f * spec_factor);
}

int	phong_model(t_scene *scene, t_hit *h)
{
	float	texture;
	t_vec4	color;
	int		i;

	color = scene->a->color;
	surface_info(h);
	i = -1;
	while (scene->l[++i])
	{
		secundary_ray(&scene->l[i]->pos, &h->pos, &h->secundary);
		if (in_shadow(scene, h))
			continue ;
		add_illumination(scene->l[i], h, &color);
	}
	texture = ((int)floorf(10 * h->texture.x) + (int)floorf(10 * h->texture.y)) % 2;
	return (rgba_to_int(ft_mulv4v(h->o->color, rgba_brightness(color, texture))));
}
