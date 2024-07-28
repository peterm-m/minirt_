/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:38:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 14:22:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_transposem2(t_matrix2 m)
{
	t_matrix2	m1;

	m1.elements[0][1] = m.elements[1][0];
	m1.elements[1][0] = m.elements[0][1];
	return (m1);
}

t_matrix3	ft_transposem3(t_matrix3 m)
{
	t_matrix3	m1;

	m1.elements[0][1] = m.elements[1][0];
	m1.elements[0][2] = m.elements[2][0];
	m1.elements[1][0] = m.elements[0][1];
	m1.elements[1][2] = m.elements[2][1];
	m1.elements[2][1] = m.elements[1][2];
	m1.elements[2][0] = m.elements[0][2];
	return (m1);
}

t_matrix4	ft_transposem4(t_matrix4 m)
{
	t_matrix4	m1;

	m1.elements[0][0] = m.elements[0][0];
	m1.elements[0][1] = m.elements[1][0];
	m1.elements[0][2] = m.elements[2][0];
	m1.elements[0][3] = m.elements[3][0];
	m1.elements[1][0] = m.elements[0][1];
	m1.elements[1][1] = m.elements[1][1];
	m1.elements[1][2] = m.elements[2][1];
	m1.elements[1][3] = m.elements[3][1];
	m1.elements[2][1] = m.elements[1][2];
	m1.elements[2][2] = m.elements[2][2];
	m1.elements[2][0] = m.elements[0][2];
	m1.elements[2][3] = m.elements[3][2];
	m1.elements[3][1] = m.elements[1][3];
	m1.elements[3][2] = m.elements[2][3];
	m1.elements[3][3] = m.elements[3][3];
	m1.elements[3][0] = m.elements[0][3];
	return (m1);
}
