/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:35:40 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:46:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	reflect_dir(t_vec3 *n, t_ray *r)
{
	return (ft_fmav3f(*n, -2.0f * ft_dotv3(*n, r->d), r->d));
}

t_vec3	refract_dir(t_vec3 *n, t_ray *r, float n1, float n2)
{
	t_vec3	aux;
	float	n_index;
	float	cos_i;
	float	sin_t2;
	float	cos_t;

	n_index = n1 / n2;
	cos_i = -1.0f * ft_dotv3(*n, r->d);
	sin_t2 = n_index * n_index * (1.0f - cos_i * cos_i);
	if (isgreater(sin_t2, 1.0f))
		return (ft_vec3(INFINITY, INFINITY, INFINITY));
	cos_t = sqrtf(1.0f - sin_t2);
	aux = ft_mulv3f(*n, n_index * cos_i - cos_t);
	aux = ft_fmav3f(r->d, n_index, aux);
	return (aux);
}

float	refractance(t_vec3 *n, t_ray *r, float n1, float n2)
{
	float	n_index;
	float	x;
	float	sin_t2;	
	float	r0;	

	r0 = (n1 - n2) / (n1 + n2);
	r0 *= r0;
	x = -1.0f * ft_dotv3(*n, r->d);
	if (n1 > n2)
	{
		n_index = n1 / n2;
		sin_t2 = n_index * n_index * (1.0f - x * x);
		if (isgreater(sin_t2, 1.0f))
			return (INFINITY);
		x = sqrtf(1.0f - sin_t2);
	}
	x = 1.0f - x;
	return (r0 + (1.0f + r0) * x * x * x * x * x);
}
