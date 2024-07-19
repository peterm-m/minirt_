/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toeachm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:52:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 13:10:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_toeachm2(t_matrix2 v, float (*f)(float))
{
	t_matrix2	a;

	a.elements[0][0] = f(v.elements[0][0]);
	a.elements[0][1] = f(v.elements[0][1]);
	a.elements[1][0] = f(v.elements[1][0]);
	a.elements[1][1] = f(v.elements[1][1]);
	return (a);
}

t_matrix3	ft_toeachm3(t_matrix3 v, float (*f)(float))
{
	t_matrix3	a;

	a.elements[0][0] = f(v.elements[0][0]);
	a.elements[0][1] = f(v.elements[0][1]);
	a.elements[0][2] = f(v.elements[0][2]);
	a.elements[1][0] = f(v.elements[1][0]);
	a.elements[1][1] = f(v.elements[1][1]);
	a.elements[1][2] = f(v.elements[1][2]);
	a.elements[2][0] = f(v.elements[2][0]);
	a.elements[2][1] = f(v.elements[2][1]);
	a.elements[2][2] = f(v.elements[2][2]);
	return (a);
}

t_matrix4	ft_toeachm4(t_matrix4 v, float (*f)(float))
{
	t_matrix4	a;

	a.elements[0][0] = f(v.elements[0][0]);
	a.elements[0][1] = f(v.elements[0][1]);
	a.elements[0][2] = f(v.elements[0][2]);
	a.elements[0][3] = f(v.elements[0][3]);
	a.elements[1][0] = f(v.elements[1][0]);
	a.elements[1][1] = f(v.elements[1][1]);
	a.elements[1][2] = f(v.elements[1][2]);
	a.elements[1][3] = f(v.elements[1][3]);
	a.elements[2][0] = f(v.elements[2][0]);
	a.elements[2][1] = f(v.elements[2][1]);
	a.elements[2][2] = f(v.elements[2][2]);
	a.elements[2][3] = f(v.elements[2][3]);
	a.elements[3][0] = f(v.elements[3][0]);
	a.elements[3][1] = f(v.elements[3][1]);
	a.elements[3][2] = f(v.elements[3][2]);
	a.elements[3][3] = f(v.elements[3][3]);
	return (a);
}
