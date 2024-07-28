/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:43:00 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 21:55:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	texture(t_hit *h)
{
	static void	(*textures[6])(t_hit *h) = {\
		texture_sp,
		texture_pl,
		texture_cy,
		texture_qd,
		texture_disk,
		texture_tr};

	textures[h->o->type](h);
}

void	texture_sp(t_hit *h)
{
	
	h->texture.x = 0.5f + atan2f(h->normal.z, h->normal.x) / (2.0f * M_PI);
	h->texture.y = 0.5f - asinf(h->normal.y) / M_PI;
}

void	texture_pl(t_hit *h)
{
	h->texture.x = 0.5f;
	h->texture.y = 0.5f;
}

void	texture_cy(t_hit *h)
{
	t_vec3	u;
	t_vec3	v;
	t_vec3	p;

	p = ft_subv3(h->pos, h->o->obj.cy.center);
	if (ft_dotv3(h->o->obj.cy.normal, ft_vec3(1.0f, 0.0f, 0.0f)) < 0.0001f)
		u = ft_cross(h->o->obj.cy.normal, ft_vec3(1.0f, 0.0f, 0.0f));
	else if (ft_dotv3(h->o->obj.cy.normal, ft_vec3(0.0f, 1.0f, 0.0f)) < 0.001f)
		u = ft_cross(h->o->obj.cy.normal, ft_vec3(0.0f, 1.0f, 0.0f));
	else
		u = ft_cross(h->o->obj.cy.normal, ft_vec3(0.0f, 0.0f, 1.0f));
	v = ft_cross(h->o->obj.cy.normal, u);
	h->texture.x = atan2f(ft_dotv3(p, v), ft_dotv3(p, u));
	h->texture.y = ft_dotv3(p, h->o->obj.cy.normal);
}

void	texture_qd(t_hit *h)
{
	t_vec4		p;
	t_matrix4	w2obj;

	w2obj = get_invtransform(h->o->obj.qd.center, h->o->obj.qd.angles, ft_vec3(1, 1, 1));
	p = ft_mulm4v(w2obj, ft_vec4(h->pos.x, h->pos.y, h->pos.z, 1.0f));
	h->texture.x = atan2f(p.z, p.x) / (2.0f * M_PI);
	h->texture.y = asinf(p.y) / M_PI;
}
