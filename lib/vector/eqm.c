/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eqm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:57:52 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 13:15:05 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

bool	ft_eqm2(t_matrix2 v1, t_matrix2 v2)
{
	return (v1.elements[0][0] == v2.elements[0][0] && \
	v1.elements[0][1] == v2.elements[0][1] && \
	v1.elements[1][0] == v2.elements[1][0] && \
	v1.elements[1][1] == v2.elements[1][1]);
}

bool	ft_eqm3(t_matrix3 v1, t_matrix3 v2)
{
	return (v1.elements[0][0] == v2.elements[0][0] && \
	v1.elements[0][1] == v2.elements[0][1] && \
	v1.elements[0][2] == v2.elements[0][2] && \
	v1.elements[1][0] == v2.elements[1][0] && \
	v1.elements[1][1] == v2.elements[1][1] && \
	v1.elements[1][2] == v2.elements[1][2] && \
	v1.elements[2][0] == v2.elements[2][0] && \
	v1.elements[2][1] == v2.elements[2][1] && \
	v1.elements[2][2] == v2.elements[2][2]);
}

bool	ft_eqm4(t_matrix4 v1, t_matrix4 v2)
{
	return (v1.elements[0][0] == v2.elements[0][0] && \
	v1.elements[0][1] == v2.elements[0][1] && \
	v1.elements[0][2] == v2.elements[0][2] && \
	v1.elements[0][3] == v2.elements[0][3] && \
	v1.elements[1][0] == v2.elements[1][0] && \
	v1.elements[1][1] == v2.elements[1][1] && \
	v1.elements[1][2] == v2.elements[1][2] && \
	v1.elements[1][3] == v2.elements[1][3] && \
	v1.elements[2][0] == v2.elements[2][0] && \
	v1.elements[2][1] == v2.elements[2][1] && \
	v1.elements[2][2] == v2.elements[2][2] && \
	v1.elements[2][3] == v2.elements[2][3] && \
	v1.elements[3][0] == v2.elements[3][0] && \
	v1.elements[3][1] == v2.elements[3][1] && \
	v1.elements[3][2] == v2.elements[3][2] && \
	v1.elements[3][3] == v2.elements[3][3]);
}
