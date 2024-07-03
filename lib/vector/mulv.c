/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mulv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:36:25 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_mulv2v(t_vec2 v1, t_vec2 v2)
{
	t_vec2	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	return (v);
}

t_vec3	ft_mulv3v(t_vec3 v1, t_vec3 v2)
{
	t_vec3	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	return (v);
}

t_vec4	ft_mulv4v(t_vec4 v1, t_vec4 v2)
{
	t_vec4	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	v.w = v1.w * v2.w;
	return (v);
}
