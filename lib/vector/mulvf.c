/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mulvf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:39:15 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_mulv2f(t_vec2 v, float f)
{
	t_vec2	v1;

	v1.x = v.x * f;
	v1.y = v.y * f;
	return (v1);
}

t_vec3	ft_mulv3f(t_vec3 v, float f)
{
	t_vec3	v1;

	v1.x = v.x * f;
	v1.y = v.y * f;
	v1.z = v.z * f;
	return (v1);
}

t_vec4	ft_mulv4f(t_vec4 v, float f)
{
	t_vec4	v1;

	v1.x = v.x * f;
	v1.y = v.y * f;
	v1.z = v.z * f;
	v1.w = v.w * f;
	return (v1);
}
