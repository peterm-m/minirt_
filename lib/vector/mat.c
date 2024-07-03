/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:19:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/22 13:37:19 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_mat2(void )
{
	t_matrix2	m;

	m.elements[0][0] = 0.0f;
	m.elements[0][1] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 0.0f;
	return (m);
}

t_matrix3	ft_mat3(void )
{
	t_matrix3	m;

	m.elements[0][0] = 0.0f;
	m.elements[0][1] = 0.0f;
	m.elements[0][2] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 0.0f;
	m.elements[1][2] = 0.0f;
	m.elements[2][0] = 0.0f;
	m.elements[2][1] = 0.0f;
	m.elements[2][2] = 0.0f;
	return (m);
}

t_matrix4	ft_mat4(void )
{
	t_matrix4	m;

	m.elements[0][0] = 0.0f;
	m.elements[0][1] = 0.0f;
	m.elements[0][2] = 0.0f;
	m.elements[0][3] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 0.0f;
	m.elements[1][2] = 0.0f;
	m.elements[1][3] = 0.0f;
	m.elements[2][0] = 0.0f;
	m.elements[2][1] = 0.0f;
	m.elements[2][2] = 0.0f;
	m.elements[2][3] = 0.0f;
	m.elements[3][0] = 0.0f;
	m.elements[3][1] = 0.0f;
	m.elements[3][2] = 0.0f;
	m.elements[3][3] = 0.0f;
	return (m);
}
