/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearcomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:09:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec4	ft_linear_combv4m4(t_vec4 v, t_matrix4 m)
{
	t_vec4	v1;

	v1.x = v.elements[0] * m.columns[0].x;
	v1.y = v.elements[0] * m.columns[0].y;
	v1.z = v.elements[0] * m.columns[0].z;
	v1.w = v.elements[0] * m.columns[0].w;
	v1.x += v.elements[1] * m.columns[1].x;
	v1.y += v.elements[1] * m.columns[1].y;
	v1.z += v.elements[1] * m.columns[1].z;
	v1.w += v.elements[1] * m.columns[1].w;
	v1.x += v.elements[2] * m.columns[2].x;
	v1.y += v.elements[2] * m.columns[2].y;
	v1.z += v.elements[2] * m.columns[2].z;
	v1.w += v.elements[2] * m.columns[2].w;
	v1.x += v.elements[3] * m.columns[3].x;
	v1.y += v.elements[3] * m.columns[3].y;
	v1.z += v.elements[3] * m.columns[3].z;
	v1.w += v.elements[3] * m.columns[3].w;
	return (v1);
}
