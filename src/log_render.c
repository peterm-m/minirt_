/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:46:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/14 18:54:48 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*log_shadow(t_scene *scene, t_hit *h)
{
	float	t;
	int		i;

	i = -1;
	printf("log shadow ");
	log_ray(&h->secundary);
	while (scene->o[++i])
	{
		t = intersection(&h->secundary, scene->o[i]);
		if (islessequal(t, h->secundary.t))
		{
			printf("shadow detected %f", t);
			break ;
		}
	}
	return (scene->o[i]);
}

static void	log_shader(t_render *r, t_hit *h)
{
	int	i;

	i = -1;
	while (r->scene->l[++i])
	{
		printf("\tTest ");
		log_light(r->scene->l[i]);
		secundary_ray(h, r->scene->l[i]);
		printf("\t\tsecundary ");
		log_ray(&h->secundary);
		if (log_shadow(r->scene, h))
		{
			printf("\t\tIn shadow\n");
			continue ;
		}
		printf("\t\tdiffuse factor %f\n", MAX(ft_dotv3(h->secundary.d, h->normal), 0.0f));
		printf("\t\tspecular factor %f\n", MAX(-2.0f * ft_dotv3(h->secundary.d, h->normal) * ft_dotv3(h->primary.d, h->normal) + ft_dotv3(h->primary.d, h->secundary.d), 0.0f));
	}
}

void	log_render(t_render *r, t_ivec2 pixel)
{
	t_hit	h;

	printf("Log ray in pixel = (%d, %d)\n\tprimary ", pixel.x, pixel.y);
	primary_ray(&pixel, r->scene->c, &h.primary);
	log_ray(&h.primary);
	first_hit(r->scene, &h);
	if (h.o == NULL)
	{
		printf("No hit\n");
		return ;
	}
	surface_info(&h);
	printf("Hit in t = %f; pos = (%f, %f, %f)\n\twhit ",
	h.primary.t, h.pos.x, h.pos.y, h.pos.z);
	log_object(h.o);
	printf("\tn = (%f, %f, %f); texture = (%f, %f)\n", h.normal.x, h.normal.y, h.normal.z, 
	h.texture.x, h.texture.y);
	log_shader(r, &h);
}
