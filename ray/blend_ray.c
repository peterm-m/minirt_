/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:35:40 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/05 12:48:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	reflect_dir(t_vec3 *n, t_ray *r)
{
	return (ft_addv3(ft_mulv3f(*n, -2.0f * ft_dotv3(r->d, *n)), r->d));
}

t_vec3	trasmision_dir(t_vec3 *n, t_ray *r, float n1, float n2)
{
	t_vec3	aux;
	float	eta;
	float	cos_i;
	float	sin_t2;
	float	cos_t;

	eta = n1 / n2;
	cos_i = -1.0f * ft_dotv3(*n, r->d);
	sin_t2 = eta * eta * (1.0f - cos_i * cos_i);
	if (isgreater(sin_t2, 1.0f))
		return (ft_vec3(INFINITY, INFINITY, INFINITY));
	cos_t = sqrtf(1.0f - sin_t2);
	aux = ft_mulv3f(*n, eta * cos_i - cos_t);
	aux = ft_fmav3f(r->d, eta, aux);
	return (aux);
}

// schlick reflectance approximation

float	refractance(t_vec3 *n, t_ray *r, float n1, float n2)
{
	float	eta;
	float	x;
	float	sin_t2;	
	float	r0;	

	r0 = (n1 - n2) / (n1 + n2);
	r0 *= r0;
	x = -1.0f * ft_dotv3(*n, r->d);
	if (n1 > n2)
	{
		eta = n1 / n2;
		sin_t2 = eta * eta * (1.0f - x * x);
		if (isgreater(sin_t2, 1.0f))
			return (INFINITY);
		x = sqrtf(1.0f - sin_t2);
	}
	x = 1.0f - x;
	return (r0 + (1.0f + r0) * x * x * x * x * x);
}
