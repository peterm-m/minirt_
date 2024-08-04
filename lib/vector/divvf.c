/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divvf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:56:42 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/04 16:09:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_divv2f(t_vec2 v, t_real f)
{
	t_vec2	v1;
	t_real	inv_f;

	inv_f = 1 / f;
	v1.x = v.x * inv_f;
	v1.y = v.y * inv_f;
	return (v1);
}

t_vec3	ft_divv3f(t_vec3 v, t_real f)
{
	t_vec3	v1;
	t_real	inv_f;

	inv_f = 1 / f;
	v1.x = v.x * inv_f;
	v1.y = v.y * inv_f;
	v1.z = v.z * inv_f;
	return (v1);
}

t_vec4	ft_divv4f(t_vec4 v, t_real f)
{
	t_vec4	v1;
	t_real	inv_f;

	inv_f = 1 / f;
	v1.x = v.x * inv_f;
	v1.y = v.y * inv_f;
	v1.z = v.z * inv_f;
	v1.w = v.w * inv_f;
	return (v1);
}
