/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:33:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/24 17:50:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	normal_disk(t_hit *h)
{
	h->normal = h->o->obj.disk.normal;
}

void	normal_tr(t_hit *h)
{
	h->normal = ft_cross(h->o->obj.tr.v0, h->o->obj.tr.v1);	
}

//void	normal_qd(t_hit *h)
//{
//	t_vec3		p;
//	t_matrix4	a;
//
//	p = h->pos;
//	a = h->o->obj.qd.a;
//	h->normal.x = 2.0f * a.elements[0][0] * p.x 
//		+ (a.elements[0][1] + a.elements[1][0]) * p.y 
//		+ (a.elements[0][2] + a.elements[2][0]) * p.z 
//		+ (a.elements[0][3] + a.elements[3][0]);
//	h->normal.y = p.x * (a.elements[0][1] + a.elements[1][0]) 
//		+ 2.0f * p.y * a.elements[1][1] 
//		+ p.z * (a.elements[1][2] + a.elements[2][1]) 
//		+ (a.elements[1][3] + a.elements[3][1]);
//	h->normal.z = p.x * (a.elements[0][2] + a.elements[2][0]) 
//		+ p.y * (a.elements[1][2] + a.elements[2][1]) 
//		+ 2.0f * p.z * a.elements[2][2] 
//		+ (a.elements[2][3] + a.elements[3][2]);
//}
