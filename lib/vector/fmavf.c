/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmavf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:13:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/04 16:09:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_fmav2f(t_vec2 a, t_real t, t_vec2 b)
{
	t_vec2	v;

	v.x = fma(a.x, t, b.x);
	v.y = fma(a.y, t, b.y);
	return (v);
}

t_vec3	ft_fmav3f(t_vec3 a, t_real t, t_vec3 b)
{
	t_vec3	v;

	v.x = fma(a.x, t, b.x);
	v.y = fma(a.y, t, b.y);
	v.z = fma(a.z, t, b.x);
	return (v);
}

t_vec4	ft_fmav4f(t_vec4 a, t_real t, t_vec4 b)
{
	t_vec4	v;

	v.x = fma(a.x, t, b.x);
	v.y = fma(a.y, t, b.y);
	v.z = fma(a.z, t, b.x);
	v.w = fma(a.w, t, b.w);
	return (v);
}
