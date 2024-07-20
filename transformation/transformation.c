/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:04:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:04:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_matrix4	get_transform(t_vec3 pos, t_vec3 rot, t_vec3 sca)
{
	t_matrix4	m;

	m = ft_ident4();
	m = ft_mulm4m(rotationr(rot.x, ft_vec3(1.0f, 0.0f, 0.0f)), m);
	m = ft_mulm4m(rotationr(rot.y, ft_vec3(0.0f, 1.0f, 0.0f)), m);
	m = ft_mulm4m(rotationr(rot.z, ft_vec3(0.0f, 0.0f, 1.0f)), m);
	m = ft_mulm4m(translate(pos), m);
	m = ft_mulm4m(scale(sca), m);
	return (m);
}

t_matrix4	get_invtransform(t_vec3 pos, t_vec3 rot, t_vec3 sca)
{
	t_matrix4	m;

	m = ft_ident4();
	m = ft_mulm4m(inv_scale(sca), m);
	m = ft_mulm4m(inv_translate(pos), m);
	m = ft_mulm4m(inv_rotation(rot.z, ft_vec3(0.0f, 0.0f, 1.0f)), m);
	m = ft_mulm4m(inv_rotation(rot.y, ft_vec3(0.0f, 1.0f, 0.0f)), m);
	m = ft_mulm4m(inv_rotation(rot.x, ft_vec3(1.0f, 0.0f, 0.0f)), m);
	return (m);
}
