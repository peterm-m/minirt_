/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:04:31 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:04:32 by pedromar         ###   ########.fr       */
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
