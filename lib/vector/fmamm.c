/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmamm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:13:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 13:12:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

#define EE elements

t_matrix2	ft_fmam2m(t_matrix2 a, t_matrix2 t, t_matrix2 b)
{
	t_matrix2	v;

	v.EE[0][0] = fma(a.EE[0][0], t.EE[0][0], b.EE[0][0]);
	v.EE[0][1] = fma(a.EE[0][1], t.EE[0][1], b.EE[0][1]);
	v.EE[1][0] = fma(a.EE[1][0], t.EE[1][0], b.EE[1][0]);
	v.EE[1][1] = fma(a.EE[1][1], t.EE[1][1], b.EE[1][1]);
	return (v);
}

t_matrix3	ft_fmam3m(t_matrix3 a, t_matrix3 t, t_matrix3 b)
{
	t_matrix3	v;

	v.EE[0][0] = fma(a.EE[0][0], t.EE[0][0], b.EE[0][0]);
	v.EE[0][1] = fma(a.EE[0][1], t.EE[0][1], b.EE[0][1]);
	v.EE[0][2] = fma(a.EE[0][2], t.EE[0][2], b.EE[0][2]);
	v.EE[1][0] = fma(a.EE[1][0], t.EE[1][0], b.EE[1][0]);
	v.EE[1][1] = fma(a.EE[1][1], t.EE[1][1], b.EE[1][1]);
	v.EE[1][2] = fma(a.EE[1][2], t.EE[1][2], b.EE[1][2]);
	v.EE[2][0] = fma(a.EE[2][0], t.EE[2][0], b.EE[2][0]);
	v.EE[2][1] = fma(a.EE[2][1], t.EE[2][1], b.EE[2][1]);
	v.EE[2][2] = fma(a.EE[2][2], t.EE[2][2], b.EE[2][2]);
	return (v);
}

t_matrix4	ft_fmam4m(t_matrix4 a, t_matrix4 t, t_matrix4 b)
{
	t_matrix4	v;

	v.EE[0][0] = fma(a.EE[0][0], t.EE[0][0], b.EE[0][0]);
	v.EE[0][1] = fma(a.EE[0][1], t.EE[0][1], b.EE[0][1]);
	v.EE[0][2] = fma(a.EE[0][2], t.EE[0][2], b.EE[0][2]);
	v.EE[0][3] = fma(a.EE[0][3], t.EE[0][3], b.EE[0][3]);
	v.EE[1][0] = fma(a.EE[1][0], t.EE[1][0], b.EE[1][0]);
	v.EE[1][1] = fma(a.EE[1][1], t.EE[1][1], b.EE[1][1]);
	v.EE[1][2] = fma(a.EE[1][2], t.EE[1][2], b.EE[1][2]);
	v.EE[1][3] = fma(a.EE[1][3], t.EE[1][3], b.EE[1][3]);
	v.EE[2][0] = fma(a.EE[2][0], t.EE[2][0], b.EE[2][0]);
	v.EE[2][1] = fma(a.EE[2][1], t.EE[2][1], b.EE[2][1]);
	v.EE[2][2] = fma(a.EE[2][2], t.EE[2][2], b.EE[2][2]);
	v.EE[2][3] = fma(a.EE[2][3], t.EE[2][3], b.EE[2][3]);
	v.EE[3][0] = fma(a.EE[3][0], t.EE[3][0], b.EE[3][0]);
	v.EE[3][1] = fma(a.EE[3][1], t.EE[3][1], b.EE[3][1]);
	v.EE[3][2] = fma(a.EE[3][2], t.EE[3][2], b.EE[3][2]);
	v.EE[3][3] = fma(a.EE[3][3], t.EE[3][3], b.EE[3][3]);
	return (v);
}
