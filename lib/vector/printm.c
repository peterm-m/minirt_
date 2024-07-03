/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:42:11 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/30 20:53:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	printm2(t_matrix2 m)
{
	printf("%f %f\n", m.elements[0][0], m.elements[0][1]);
	printf("%f %f\n", m.elements[1][0], m.elements[1][1]);
}

void	printm3(t_matrix3 m)
{
	printf("%f %f %f \n", m.elements[0][0], m.elements[0][1],
		m.elements[0][2]);
	printf("%f %f %f \n", m.elements[1][0], m.elements[1][1],
		m.elements[1][2]);
	printf("%f %f %f \n", m.elements[2][0], m.elements[2][1],
		m.elements[2][2]);
}

void	printm4(t_matrix4 m)
{
	printf("%f %f %f %f\n", m.elements[0][0], m.elements[0][1],
		m.elements[0][2], m.elements[0][3]);
	printf("%f %f %f %f\n", m.elements[1][0], m.elements[1][1],
		m.elements[1][2], m.elements[1][3]);
	printf("%f %f %f %f\n", m.elements[2][0], m.elements[2][1],
		m.elements[2][2], m.elements[2][3]);
	printf("%f %f %f %f\n", m.elements[3][0], m.elements[3][1],
		m.elements[3][2], m.elements[3][3]);
}
