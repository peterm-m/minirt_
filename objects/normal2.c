/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:31:10 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	normal_disk(t_hit *h)
{
	h->normal = h->o->obj.disk.normal;
	if (isless(ft_dotv3(h->o->obj.disk.normal, h->primary.d), 0.0))
		h->normal = ft_divv3f(h->normal, -1.0f);
}

void	normal_tr(t_hit *h)
{
	t_vec3	normal;
	float	a;

	normal = ft_cross(h->o->obj.tr.v0, h->o->obj.tr.v1);
	a = ft_lenv3(normal);
	if (!isgreater(ft_dotv3(normal, h->primary.d), 0.0))
		h->normal = ft_divv3f(normal, a);
	else
		h->normal = ft_divv3f(normal, -1.0f * a);
	return ;
}
