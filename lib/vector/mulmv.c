/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mulmv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:17:47 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_mulm2v(t_matrix2 m, t_vec2 v)
{
	t_vec2	v1;

	v1.x = v.elements[0] * m.columns[0].x;
	v1.y = v.elements[0] * m.columns[0].y;
	v1.x += v.elements[1] * m.columns[1].x;
	v1.y += v.elements[1] * m.columns[1].y;
	return (v1);
}

t_vec3	ft_mulm3v(t_matrix3 m, t_vec3 v)
{
	t_vec3	v1;

	v1.x = v.elements[0] * m.columns[0].x;
	v1.y = v.elements[0] * m.columns[0].y;
	v1.z = v.elements[0] * m.columns[0].z;
	v1.x += v.elements[1] * m.columns[1].x;
	v1.y += v.elements[1] * m.columns[1].y;
	v1.z += v.elements[1] * m.columns[1].z;
	v1.x += v.elements[2] * m.columns[2].x;
	v1.y += v.elements[2] * m.columns[2].y;
	v1.z += v.elements[2] * m.columns[2].z;
	return (v1);
}

t_vec4	ft_mulm4v(t_matrix4 m, t_vec4 v)
{
	return (ft_linear_combv4m4(v, m));
}
