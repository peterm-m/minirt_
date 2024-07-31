/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:32:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 16:49:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	phong_term(t_light *l, t_hit *h, t_vec4 *color)
{
	float	geometric_factor;
	float	diff_factor;
	float	spec_factor;

	diff_factor = ft_dotv3(h->secundary.d, h->normal);
	if (islessequal(diff_factor, 0.0f))
		return ;
	spec_factor = -2.0f * diff_factor * ft_dotv3(h->primary.d, h->normal)
		+ ft_dotv3(h->primary.d, h->secundary.d);
	spec_factor = pow(MAX(spec_factor, 0.0f), h->o->material.glossiness);
	geometric_factor = 1.0f;
	rgba_sum(color, ft_mulv4v(l->color, h->data_o[DIFFUSE]), \
		diff_factor * geometric_factor);
	rgba_sum(color, ft_mulv4v(l->color, h->data_o[SPECULAR]), \
		spec_factor * geometric_factor);
}
