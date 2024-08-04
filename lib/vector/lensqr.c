/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lensqr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:33:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/04 16:09:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_real	ft_lensqrv2(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

t_real	ft_lensqrv3(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_real	ft_lensqrv4(t_vec4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
