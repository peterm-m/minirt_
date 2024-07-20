/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:43:00 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 13:16:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	texture(t_hit *h)
{
	static void	(*textures[6])(t_hit *h) = {\
		texture_sp,
		texture_pl,
		texture_cy,
		texture_cn,
		texture_disk,
		texture_tr};

	textures[h->o->type](h);
}

void	texture_sp(t_hit *h)
{
	h->texture = ft_vec2(\
		0.5f + atan2f(h->normal.z, h->normal.x) / (2.0f * M_PI), \
		0.5f - asinf(h->normal.y) / M_PI);
}

/*
* TODO
*/

void	texture_pl(t_hit *h)
{
	h->texture = ft_vec2(h->pos.x, h->pos.y);
}

/*
* TODO
*/

void	texture_cy(t_hit *h)
{
	h->texture = ft_vec2(1.0f, 0.0f);
}

/*
* TODO
*/

void	texture_cn(t_hit *h)
{
	h->texture = ft_vec2(1.0f, 0.0f);
}
