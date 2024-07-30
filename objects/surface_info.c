/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:01:32 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 17:46:18 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	surface_info(t_hit *h)
{
	h->pos = ft_fmav3f(h->primary.d, BIAS_RAY * h->primary.t, h->primary.o);
	normal(h);
	texture(h);
	if (h->o->material.mat_info & HAVE_TEXTURE)
	{
		get_pixel_xpm(h->o->material.texture, &h->texture);
	}
}
