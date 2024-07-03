/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eqv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:57:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

bool	ft_eqv2(t_vec2 v1, t_vec2 v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}

bool	ft_eqv3(t_vec3 v1, t_vec3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

bool	ft_eqv4(t_vec4 v1, t_vec4 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w);
}
