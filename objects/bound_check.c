/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:23:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 18:54:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	bound_check(t_ray *r, t_bound *b)
{
	float	t_max;
	float	t_min;
	float	t1;
	float	t2;

	t1 = (b->p_min.x - r->o.x) / r->d.x;
	t2 = (b->p_max.x - r->o.x) / r->d.x;
	t_max = MAX(t1, t2);
	t_min = MIN(t1, t2);
	t1 = (b->p_min.y - r->o.y) / r->d.y;
	t2 = (b->p_max.y - r->o.y) / r->d.y;
	t_max = MIN(t_max, MAX(t1, t2));
	t_min = MAX(t_min, MIN(t1, t2));
	t1 = (b->p_min.z - r->o.z) / r->d.z;
	t2 = (b->p_max.z - r->o.z) / r->d.z;
	t_max = MIN(t_max, MAX(t1, t2));
	t_min = MAX(t_min, MIN(t1, t2));
	if (isgreater(t_min, t_max) || isless(t_max, 0.0f))
		return (INFINITY);
	else
		return (t_min + isless(t_min, 0.0f) * (t_max - t_min));
}
