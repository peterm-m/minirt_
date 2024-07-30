/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:04:09 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 15:20:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	transform_vec(t_matrix4 *m, t_vec3 *in, t_vec3 *out)
{
	t_vec4	aux;

	aux = ft_mulm4v(*m, ft_vec4(in->x, in->y, in->z, 1.0f));
	out->x = aux.x / aux.w;
	out->y = aux.y / aux.w;
	out->z = aux.z / aux.w;
}

void	transform_dir(t_matrix4 *m, t_vec3 *in, t_vec3 *out)
{
	t_vec4	aux;

	aux = ft_mulm4v(*m, ft_vec4(in->x, in->y, in->z, 0.0f));
	out->x = aux.x;
	out->y = aux.y;
	out->z = aux.z;
}

void	transform_matrix(t_matrix4 *m, t_matrix4 *in, t_matrix4 *out)
{
	*out = ft_mulm4m(ft_mulm4m(ft_transposem4(*m), *in), *m);
}
