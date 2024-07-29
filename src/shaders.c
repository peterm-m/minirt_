/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:32:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/29 21:10:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * TODO: need parameter for specular term shine 50.0f and ks 0.6
*/

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
	spec_factor = pow(MAX(spec_factor, 0.0f), 100.0f);
	geometric_factor = 1.0f / (h->secundary.t * h->secundary.t);
	rgba_sum(color, l->color, diff_factor * geometric_factor);
	rgba_sum(color, l->color, 0.6f * spec_factor * geometric_factor);
}
