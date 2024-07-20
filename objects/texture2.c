/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:43:00 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:28:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <sys/param.h>

/*
* TODO
*/

void	texture_disk(t_hit *h)
{
	h->texture = ft_vec2(1.0f, 0.0f);
}

/*
* TODO
*/

void	texture_tr(t_hit *h)
{
	h->texture = ft_vec2(1.0f, 0.0f);
}
