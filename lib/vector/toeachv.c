/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toeachv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:52:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 13:10:38 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_toeachv2(t_vec2 v, float (*f)(float))
{
	t_vec2	a;

	a.x = f(v.x);
	a.y = f(v.y);
	return (a);
}

t_vec3	ft_toeachv3(t_vec3 v, float (*f)(float))
{
	t_vec3	a;

	a.x = f(v.x);
	a.y = f(v.y);
	a.z = f(v.z);
	return (a);
}

t_vec4	ft_toeachv4(t_vec4 v, float (*f)(float))
{
	t_vec4	a;

	a.x = f(v.x);
	a.y = f(v.y);
	a.z = f(v.z);
	a.w = f(v.w);
	return (a);
}
