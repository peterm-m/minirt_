/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:43:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/21 18:16:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*check_shadow(t_scene *scene, t_hit *h)
{
	float	t;
	int		i;

	i = -1;
	while (scene->o[++i])
	{
		if (isfinite(bound_check(&h->secundary, scene->o[i])))
		{
			t = intersection(&h->secundary, scene->o[i]);
			if (isfinite(t) && isless(t, h->secundary.t))
				break ;
		}
	}
	return (scene->o[i]);
}

void	check_hit(t_scene *scene, t_hit *hit)
{
	float	aux;
	int		i;

	i = -1;
	hit->o = NULL;
	aux = INFINITY;
	while (scene->o[++i])
	{
		if (bound_check(&hit->primary, scene->o[i]) < aux)
		{
			aux = intersection(&hit->primary, scene->o[i]);
			if (isfinite(aux) && isless(aux, hit->primary.t))
			{
				hit->primary.t = aux;
				hit->o = scene->o[i];
			}
		}
	}
}
