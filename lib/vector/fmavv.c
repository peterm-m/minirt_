/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmavv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:13:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 12:39:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_fmav2v(t_vec2 a, t_vec2 t, t_vec2 b)
{
	t_vec2	v;

	v.x = fma(a.x, t.x, b.x);
	v.y = fma(a.y, t.y, b.y);
	return (v);
}

t_vec3	ft_fmav3v(t_vec3 a, t_vec3 t, t_vec3 b)
{
	t_vec3	v;

	v.x = fma(a.x, t.x, b.x);
	v.y = fma(a.y, t.y, b.y);
	v.z = fma(a.z, t.z, b.x);
	return (v);
}

t_vec4	ft_fmav4v(t_vec4 a, t_vec4 t, t_vec4 b)
{
	t_vec4	v;

	v.x = fma(a.x, t.x, b.x);
	v.y = fma(a.y, t.y, b.y);
	v.z = fma(a.z, t.z, b.x);
	v.w = fma(a.w, t.w, b.w);
	return (v);
}
