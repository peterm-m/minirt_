/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:46:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/16 19:03:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	log_shader(t_render *r, t_hit *h)
{
	int	i;
	t_object  *o;

	i = -1;
	while (r->scene->l[++i])
	{
		printf("--------------------------------- Test Light ---------------------------------\n");
		log_light(r->scene->l[i]);
		secundary_ray(h->pos, r->scene->l[i]->pos, &h->secundary);
		printf("secundary ");
		log_ray(&h->secundary);
		if ((o = in_shadow(r->scene, h)))
		{
			log_object(o);
			printf("--------------------------------- In shadow \n");
			continue ;
		}
		printf("diffuse factor %f\n", ft_dotv3(h->secundary.d, h->normal));
		printf("specular factor %f\n", -2.0f * ft_dotv3(h->secundary.d, h->normal) * ft_dotv3(h->primary.d, h->normal) + ft_dotv3(h->primary.d, h->secundary.d));
	}
}

void	log_render(t_render *r, t_ivec2 pixel)
{
	t_hit	h;

	printf("--------------------------------- LOG RAY ---------------------------------\n");
	printf("Log ray in pixel = (%d, %d)\n\tprimary ", pixel.x, pixel.y);
	primary_ray(&pixel, r->scene->c, &h.primary); 
	log_ray(&h.primary);
	first_hit(r->scene, &h);
	if (h.o == NULL)
	{
		printf("No hit\n");
		return ;
	}
	printf("Hit in t = %f; pos = (%f, %f, %f) with \n",
	h.primary.t, h.pos.x, h.pos.y, h.pos.z);
	surface_info(&h);
	log_object(h.o);
	printf("n = (%f, %f, %f); texture = (%f, %f)\n", h.normal.x, h.normal.y, h.normal.z, h.texture.x, h.texture.y);
	log_shader(r, &h);
	return ;
}
