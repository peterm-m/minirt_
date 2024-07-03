/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mulmm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:28:38 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix2	ft_mulm2m(t_matrix2 m1, t_matrix2 m2)
{
	t_matrix2	m;

	m.columns[0] = ft_mulm2v(m1, m2.columns[0]);
	m.columns[1] = ft_mulm2v(m1, m2.columns[1]);
	return (m);
}

t_matrix3	ft_mulm3m(t_matrix3 m1, t_matrix3 m2)
{
	t_matrix3	m;

	m.columns[0] = ft_mulm3v(m1, m2.columns[0]);
	m.columns[1] = ft_mulm3v(m1, m2.columns[1]);
	m.columns[2] = ft_mulm3v(m1, m2.columns[2]);
	return (m);
}

t_matrix4	ft_mulm4m(t_matrix4 m1, t_matrix4 m2)
{
	t_matrix4	m;

	m.columns[0] = ft_linear_combv4m4(m1.columns[0], m2);
	m.columns[1] = ft_linear_combv4m4(m1.columns[1], m2);
	m.columns[2] = ft_linear_combv4m4(m1.columns[2], m2);
	m.columns[3] = ft_linear_combv4m4(m1.columns[3], m2);
	return (m);
}
