/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:01:32 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/14 18:58:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	surface_info(t_hit *h)
{
	h->secundary.o = ft_addv3(ft_mulv3f(h->primary.d, h->primary.t), h->primary.o);
	normal(h);
	texture(h);
}
