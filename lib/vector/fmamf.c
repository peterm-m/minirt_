/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmamf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:13:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 12:44:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_fmam2f(t_matrix2 a, float t, t_matrix2 b)
{
	t_matrix2	v;

	v.elements[0][0] = fma(a.elements[0][0], t, b.elements[0][0]);
	v.elements[0][1] = fma(a.elements[0][1], t, b.elements[0][1]);
	v.elements[1][0] = fma(a.elements[1][0], t, b.elements[1][0]);
	v.elements[1][1] = fma(a.elements[1][1], t, b.elements[1][1]);
	return (v);
}

t_matrix3	ft_fmam3f(t_matrix3 a, float t, t_matrix3 b)
{
	t_matrix3	v;

	v.elements[0][0] = fma(a.elements[0][0], t, b.elements[0][0]);
	v.elements[0][1] = fma(a.elements[0][1], t, b.elements[0][1]);
	v.elements[0][2] = fma(a.elements[0][2], t, b.elements[0][2]);
	v.elements[1][0] = fma(a.elements[1][0], t, b.elements[1][0]);
	v.elements[1][1] = fma(a.elements[1][1], t, b.elements[1][1]);
	v.elements[1][2] = fma(a.elements[1][2], t, b.elements[1][2]);
	v.elements[2][0] = fma(a.elements[2][0], t, b.elements[2][0]);
	v.elements[2][1] = fma(a.elements[2][1], t, b.elements[2][1]);
	v.elements[2][2] = fma(a.elements[2][2], t, b.elements[2][2]);
	return (v);
}

t_matrix4	ft_fmam4f(t_matrix4 a, float t, t_matrix4 b)
{
	t_matrix4	v;

	v.elements[0][0] = fma(a.elements[0][0], t, b.elements[0][0]);
	v.elements[0][1] = fma(a.elements[0][1], t, b.elements[0][1]);
	v.elements[0][2] = fma(a.elements[0][2], t, b.elements[0][2]);
	v.elements[0][3] = fma(a.elements[0][3], t, b.elements[0][3]);
	v.elements[1][0] = fma(a.elements[1][0], t, b.elements[1][0]);
	v.elements[1][1] = fma(a.elements[1][1], t, b.elements[1][1]);
	v.elements[1][2] = fma(a.elements[1][2], t, b.elements[1][2]);
	v.elements[1][3] = fma(a.elements[1][3], t, b.elements[1][3]);
	v.elements[2][0] = fma(a.elements[2][0], t, b.elements[2][0]);
	v.elements[2][1] = fma(a.elements[2][1], t, b.elements[2][1]);
	v.elements[2][2] = fma(a.elements[2][2], t, b.elements[2][2]);
	v.elements[2][3] = fma(a.elements[2][3], t, b.elements[2][3]);
	v.elements[3][0] = fma(a.elements[3][0], t, b.elements[3][0]);
	v.elements[3][1] = fma(a.elements[3][1], t, b.elements[3][1]);
	v.elements[3][2] = fma(a.elements[3][2], t, b.elements[3][2]);
	v.elements[3][3] = fma(a.elements[3][3], t, b.elements[3][3]);
	return (v);
}
