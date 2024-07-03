/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:28:36 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:50:56 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_addm2(t_matrix2 m1, t_matrix2 m2)
{
	t_matrix2	m;

	m.elements[0][0] = m1.elements[0][0] + m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] + m2.elements[0][1];
	m.elements[1][0] = m1.elements[1][0] + m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] + m2.elements[1][1];
	return (m);
}

t_matrix3	ft_addm3(t_matrix3 m1, t_matrix3 m2)
{
	t_matrix3	m;

	m.elements[0][0] = m1.elements[0][0] + m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] + m2.elements[0][1];
	m.elements[0][2] = m1.elements[0][2] + m2.elements[0][2];
	m.elements[1][0] = m1.elements[1][0] + m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] + m2.elements[1][1];
	m.elements[1][2] = m1.elements[1][2] + m2.elements[1][2];
	m.elements[2][0] = m1.elements[2][0] + m2.elements[2][0];
	m.elements[2][1] = m1.elements[2][1] + m2.elements[2][1];
	m.elements[2][2] = m1.elements[2][2] + m2.elements[2][2];
	return (m);
}

t_matrix4	ft_addm4(t_matrix4 m1, t_matrix4 m2)
{
	t_matrix4	m;

	m.elements[0][0] = m1.elements[0][0] + m2.elements[0][0];
	m.elements[0][1] = m1.elements[0][1] + m2.elements[0][1];
	m.elements[0][2] = m1.elements[0][2] + m2.elements[0][2];
	m.elements[0][3] = m1.elements[0][3] + m2.elements[0][3];
	m.elements[1][0] = m1.elements[1][0] + m2.elements[1][0];
	m.elements[1][1] = m1.elements[1][1] + m2.elements[1][1];
	m.elements[1][2] = m1.elements[1][2] + m2.elements[1][2];
	m.elements[1][3] = m1.elements[1][3] + m2.elements[1][3];
	m.elements[2][0] = m1.elements[2][0] + m2.elements[2][0];
	m.elements[2][1] = m1.elements[2][1] + m2.elements[2][1];
	m.elements[2][2] = m1.elements[2][2] + m2.elements[2][2];
	m.elements[2][3] = m1.elements[2][3] + m2.elements[2][3];
	m.elements[3][0] = m1.elements[3][0] + m2.elements[3][0];
	m.elements[3][1] = m1.elements[3][1] + m2.elements[3][1];
	m.elements[3][2] = m1.elements[3][2] + m2.elements[3][2];
	m.elements[3][3] = m1.elements[3][3] + m2.elements[3][3];
	return (m);
}
