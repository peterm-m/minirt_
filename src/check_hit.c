/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/05 16:20:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO: include index for initial loop

bool	check_shadow(t_scene *scene, t_hit *h, int light)
{
	int		i;

	i = -1;
	gen_ray(h->pos, scene->l[light]->pos, &h->secundary);
	if (isless(ft_dotv3(h->secundary.d, h->normal), 0.0f))
		return (false);
	while (scene->o[++i])
		if (isless(intersection(&h->secundary, scene->o[i]), h->secundary.t))
			break ;
	return (scene->o[i] == NULL);
}

bool	check_hit(t_scene *scene, t_hit *hit)
{
	float	aux;
	int		i;

	i = -1;
	hit->o = NULL;
	aux = INFINITY;
	while (scene->o[++i])
	{
		aux = intersection(&hit->primary, scene->o[i]);
		if (isless(aux, hit->primary.t))
		{
			hit->primary.t = aux;
			hit->o = scene->o[i];
		}
	}
	return (hit->o != NULL);
}
