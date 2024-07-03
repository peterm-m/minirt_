/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:12:31 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_ident2(void )
{
	t_matrix2	m;

	m.elements[0][0] = 1.0f;
	m.elements[0][1] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 1.0f;
	return (m);
}

t_matrix3	ft_ident3(void )
{
	t_matrix3	m;

	m.elements[0][0] = 1.0f;
	m.elements[0][1] = 0.0f;
	m.elements[0][2] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 1.0f;
	m.elements[1][2] = 0.0f;
	m.elements[2][0] = 0.0f;
	m.elements[2][1] = 0.0f;
	m.elements[2][2] = 1.0f;
	return (m);
}

t_matrix4	ft_ident4(void )
{
	t_matrix4	m;

	m.elements[0][0] = 1.0f;
	m.elements[0][1] = 0.0f;
	m.elements[0][2] = 0.0f;
	m.elements[0][3] = 0.0f;
	m.elements[1][0] = 0.0f;
	m.elements[1][1] = 1.0f;
	m.elements[1][2] = 0.0f;
	m.elements[1][3] = 0.0f;
	m.elements[2][0] = 0.0f;
	m.elements[2][1] = 0.0f;
	m.elements[2][2] = 1.0f;
	m.elements[2][3] = 0.0f;
	m.elements[3][0] = 0.0f;
	m.elements[3][1] = 0.0f;
	m.elements[3][2] = 0.0f;
	m.elements[3][3] = 1.0f;
	return (m);
}
