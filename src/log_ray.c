/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:46:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 19:29:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	log_ray(t_ray *r)
{
	printf("ray: d = (%f, %f, %f); o = (%f, %f, %f)\n",
	r->d.x, r->d.y, r->d.z, r->o.x, r->o.y, r->o.z);
}

void	log_history_ray(t_render *r, t_ivec2 pixel)
{
	int		i;
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
	i = -1;
	while (r->scene->l[++i])
	{
		printf("\tTest ");
		log_light(r->scene->l[i]);
		secundary_ray(&r->scene->l[i]->pos, &h.pos, &h.secundary);
		printf("\t\tsecundary ");
		log_ray(&h.secundary);
		if (in_shadow(r->scene, &h))
		{
			printf("\t\tIn shadow\n");
			continue ;
		}
		printf("\t\tdiffuse factor %f\n", ft_dotv3(h.secundary.d, h.normal));
		printf("\t\tspecular factor %f\n", -2.0f * ft_dotv3(h.secundary.d, h.normal) * ft_dotv3(h.primary.d, h.normal) + ft_dotv3(h.primary.d, h.secundary.d));
	}
}
