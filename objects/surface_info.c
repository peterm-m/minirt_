/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:01:32 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/05 16:33:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	pattern(t_hit *h)
{
	float	factor_x;
	float	factor_y;

	factor_x = (10.0f * h->texture.x - floor(10.0f * h->texture.x));
	factor_y = (10.0f * h->texture.y - floor(10.0f * h->texture.y));
	return (isless(factor_x, 0.5f) ^ isless(factor_y, 0.5f));
}

static void	data_object(t_hit *h)
{
	float	pattern_factor;

	pattern_factor = 1.0f;
	if (h->o->material.mat_info & HAVE_PATTERN)
		pattern_factor = pattern(h);
	if (h->o->material.mat_info & HAVE_TEXTURE)
	{
		h->data_o[AMBIENT] = get_pixel_xpm(h->o->material.texture, &h->texture);
		h->data_o[DIFFUSE] = ft_mulv4f(h->data_o[AMBIENT], pattern_factor);
		h->data_o[SPECULAR] = h->data_o[DIFFUSE];
	}
	else
	{
		h->data_o[AMBIENT] = h->o->material.k_a;
		h->data_o[DIFFUSE] = ft_mulv4f(h->o->material.k_d, pattern_factor);
		h->data_o[SPECULAR] = ft_mulv4f(h->o->material.k_s, pattern_factor);
	}
}

void	surface_info(t_hit *h)
{
	h->pos = ft_fmav3f(h->primary.d, BIAS_RAY * h->primary.t, h->primary.o);
	normal(h);
	texture(h);
	data_object(h);
}
