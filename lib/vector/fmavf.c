/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmavf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:13:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/05 13:50:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_fmav2f(t_vec2 a, t_real t, t_vec2 b)
{
	t_vec2	v;

	v.x = fmaf(a.x, t, b.x);
	v.y = fmaf(a.y, t, b.y);
	return (v);
}

t_vec3	ft_fmav3f(t_vec3 a, t_real t, t_vec3 b)
{
	t_vec3	v;

	v.x = fmaf(a.x, t, b.x);
	v.y = fmaf(a.y, t, b.y);
	v.z = fmaf(a.z, t, b.x);
	return (v);
}

t_vec4	ft_fmav4f(t_vec4 a, t_real t, t_vec4 b)
{
	t_vec4	v;

	v.x = fmaf(a.x, t, b.x);
	v.y = fmaf(a.y, t, b.y);
	v.z = fmaf(a.z, t, b.x);
	v.w = fmaf(a.w, t, b.w);
	return (v);
}
