/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:01:32 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 21:57:44 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	surface_info(t_hit *h)
{
	h->pos = ft_addv3(ft_mulv3f(h->primary.d, h->primary.t), h->primary.o);
	normal(h);
	texture(h);
}
