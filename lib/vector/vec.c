/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:15:35 by pedromar          #+#    #+#             */
/*   Updated: 2024/06/18 10:39:33 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_vec2(float x, float y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec3	ft_vec3(float x, float y, float z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec4	ft_vec4(float x, float y, float z, float w)
{
	t_vec4	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}
