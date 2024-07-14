/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:38:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/06 18:07:13 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_matrix4	translate(t_vec3 translation)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[3][0] = translation.x;
	m.elements[3][1] = translation.y;
	m.elements[3][2] = translation.z;
	return (m);
}

t_matrix4	inv_translate(t_vec3 translation)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[3][0] = -translation.x;
	m.elements[3][1] = -translation.y;
	m.elements[3][2] = -translation.z;
	return (m);
}
