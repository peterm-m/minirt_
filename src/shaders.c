/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:32:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 21:07:47 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*in_shadow(t_scene *scene, t_hit *h)
{
	float 	t;
	int		i;

	i = -1;
	while (scene->o[++i])
	{
		t = intersection(&h->secundary, scene->o[i]);
		if (isfinite(t) && isless(t, h->secundary.t))
			break ;
	}
	return (scene->o[i]);
}

/*
 * TODO: need parameter for specular term shine 50.0f and ks 0.6
*/

static void	phong_term(t_light *l, t_hit *h, t_vec4 *color)
{
	float	diff_factor;
	float	spec_factor;

	diff_factor = ft_dotv3(h->secundary.d, h->normal);
	if (islessequal(diff_factor, 0.0f))
		return ;
	spec_factor = -2.0f * diff_factor * ft_dotv3(h->primary.d, h->normal)
		+ ft_dotv3(h->primary.d, h->secundary.d);
	spec_factor = pow(MAX(spec_factor, 0.0f), 100.0f);
	rgba_sum(color, l->color, diff_factor);// (h->secundary.t * h->secundary.t));
	rgba_sum(color, l->color, 0.6f * spec_factor);// / (h->secundary.t * h->secundary.t));
}

int	shading(t_scene *scene, t_hit *h)
{
	//static t_xpm	*xpm;
	//if (!xpm)
	//	xpm = ft_xpm_image("/home/pedromar/code/minirt_/spacee.xpm");
	t_vec4	color;
	int		i;

	color = scene->a->color;
	surface_info(h);
	i = -1;
	while (scene->l[++i])
	{
		gen_secundary(h->pos, scene->l[i]->pos, &h->secundary);
		if (in_shadow(scene, h))
			continue ;
		phong_term(scene->l[i], h, &color);
	}
	//if (h->o->type == obj_sphere) {
	//	h->o->color = int_to_rgba(get_pixel_xpm(xpm, (t_ivec2){.x = (int)floorf(xpm->h * h->texture.x), .y = (int)floorf(xpm->w * h->texture.y)}));
	//}
	return (rgba_to_int(ft_mulv4v(h->o->color, color)));
}
