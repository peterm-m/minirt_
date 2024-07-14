/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:15:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/06 18:07:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_matrix4	lookatr(t_vec3 target, t_vec3 updir, t_vec3 eye)
{
	t_matrix4	m;
	t_vec3		forward;
	t_vec3		left;
	t_vec3		up;

	forward = ft_subv3(eye, target);
	forward = ft_divv3f(forward, ft_lenv3(forward));
	left = ft_cross(updir, forward);
	left = ft_divv3f(left, ft_lenv3(left));
	up = ft_cross(left, forward);
	m = ft_mat4();
	m.elements[0][0] = left.x;
	m.elements[0][1] = up.x;
	m.elements[0][2] = -forward.x;
	m.elements[1][0] = left.y;
	m.elements[1][1] = up.y;
	m.elements[1][2] = -forward.y;
	m.elements[2][0] = left.z;
	m.elements[2][1] = up.z;
	m.elements[2][2] = -forward.z;
	m.elements[3][0] = -ft_dotv3(left, eye);
	m.elements[3][1] = -ft_dotv3(up, eye);
	m.elements[3][2] = ft_dotv3(forward, eye);
	m.elements[3][3] = 1.0f;
	return (m);
}

t_matrix4	lookatl(t_vec3 target, t_vec3 updir, t_vec3 eye)
{
	t_matrix4	m;
	t_vec3		forward;
	t_vec3		left;
	t_vec3		up;

	forward = ft_subv3(target, eye);
	forward = ft_divv3f(forward, ft_lenv3(forward));
	left = ft_cross(updir, forward);
	left = ft_divv3f(left, ft_lenv3(left));
	up = ft_cross(left, forward);
	m = ft_mat4();
	m.elements[0][0] = left.x;
	m.elements[0][1] = up.x;
	m.elements[0][2] = -forward.x;
	m.elements[1][0] = left.y;
	m.elements[1][1] = up.y;
	m.elements[1][2] = -forward.y;
	m.elements[2][0] = left.z;
	m.elements[2][1] = up.z;
	m.elements[2][2] = -forward.z;
	m.elements[3][0] = -ft_dotv3(left, eye);
	m.elements[3][1] = -ft_dotv3(up, eye);
	m.elements[3][2] = ft_dotv3(forward, eye);
	m.elements[3][3] = 1.0f;
	return (m);
}

t_matrix4	inv_lookat(t_matrix4 lookat_m)
{
	t_matrix4	m;
	t_matrix3	rot;

	rot.columns[0] = lookat_m.columns[0].xyz;
	rot.columns[1] = lookat_m.columns[1].xyz;
	rot.columns[2] = lookat_m.columns[2].xyz;
	rot = ft_transposem3(rot);
	m.columns[0].xyz = rot.columns[0];
	m.columns[0].w = 0.0f;
	m.columns[1].xyz = rot.columns[0];
	m.columns[1].w = 0.0f;
	m.columns[2].xyz = rot.columns[0];
	m.columns[2].w = 0.0f;
	m.columns[3] = ft_mulv4f(lookat_m.columns[3], -1.0f);
	m.elements[3][0] = -1.0f * lookat_m.elements[3][0]
		/ (rot.elements[0][0] + rot.elements[0][1] + rot.elements[0][2]);
	m.elements[3][1] = -1.0f * lookat_m.elements[3][1]
		/ (rot.elements[1][0] + rot.elements[1][1] + rot.elements[1][2]);
	m.elements[3][2] = -1.0f * lookat_m.elements[3][2]
		/ (rot.elements[2][0] + rot.elements[2][1] + rot.elements[2][2]);
	m.elements[3][3] = 1.0f;
	return (m);
}
