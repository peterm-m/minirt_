/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divmf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:53:44 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_divm2f(t_matrix2 m, float f)
{
	t_matrix2	m1;

	m1.elements[0][0] = m.elements[0][0] / f;
	m1.elements[0][1] = m.elements[0][1] / f;
	m1.elements[1][0] = m.elements[1][0] / f;
	m1.elements[1][1] = m.elements[1][1] / f;
	return (m1);
}

t_matrix3	ft_divm3f(t_matrix3 m, float f)
{
	t_matrix3	m1;

	m1.elements[0][0] = m.elements[0][0] / f;
	m1.elements[0][1] = m.elements[0][1] / f;
	m1.elements[0][2] = m.elements[0][2] / f;
	m1.elements[1][0] = m.elements[1][0] / f;
	m1.elements[1][1] = m.elements[1][1] / f;
	m1.elements[1][2] = m.elements[1][2] / f;
	m1.elements[2][0] = m.elements[2][0] / f;
	m1.elements[2][1] = m.elements[2][1] / f;
	m1.elements[2][2] = m.elements[2][2] / f;
	return (m1);
}

t_matrix4	ft_divm4f(t_matrix4 m, float f)
{
	t_matrix4	m1;

	m1.elements[0][0] = m.elements[0][0] / f;
	m1.elements[0][1] = m.elements[0][1] / f;
	m1.elements[0][2] = m.elements[0][2] / f;
	m1.elements[0][3] = m.elements[0][3] / f;
	m1.elements[1][0] = m.elements[1][0] / f;
	m1.elements[1][1] = m.elements[1][1] / f;
	m1.elements[1][2] = m.elements[1][2] / f;
	m1.elements[1][3] = m.elements[1][3] / f;
	m1.elements[2][0] = m.elements[2][0] / f;
	m1.elements[2][1] = m.elements[2][1] / f;
	m1.elements[2][2] = m.elements[2][2] / f;
	m1.elements[2][3] = m.elements[2][3] / f;
	m1.elements[3][0] = m.elements[3][0] / f;
	m1.elements[3][1] = m.elements[3][1] / f;
	m1.elements[3][2] = m.elements[3][2] / f;
	m1.elements[3][3] = m.elements[3][3] / f;
	return (m1);
}
