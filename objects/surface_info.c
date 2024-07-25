/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:01:32 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/25 19:37:16 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	surface_info(t_hit *h)
{
	h->pos = ft_fmav3f(h->primary.d, BIAS_RAY * h->primary.t, h->primary.o);
	//h->color = h->o->color; // Aqui se elige si el color se mira en un xpm, chesstable effect, etc
	normal(h);
	texture(h);
}
