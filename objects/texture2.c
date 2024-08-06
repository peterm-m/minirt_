/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:43:00 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/06 15:34:14 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
* TODO
*/

void	texture_disk(t_hit *h, t_vec3 *uv)
{
	(void)uv;
	h->texture = ft_vec2(1.0f, 0.0f);
}

/*
* TODO
*/

void	texture_tr(t_hit *h, t_vec3 *uv)
{
	(void)uv;
	h->texture = ft_vec2(1.0f, 0.0f);
}
