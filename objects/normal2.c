/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/27 19:07:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	normal_disk(t_hit *h)
{
	h->normal = h->o->obj.disk.normal;
}

void	normal_tr(t_hit *h)
{
	h->normal = h->o->obj.tr.n;
}

