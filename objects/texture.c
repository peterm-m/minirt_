/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:43:00 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/08 20:29:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	texture(t_hit *h)
{
	static void	(*textures[6])(t_hit *h, t_vec3 *) = {\
		texture_sp,
		texture_pl,
		texture_cy,
		texture_qd};
	t_vec3		uv[2];
	t_vec4		bump_uv;
	t_vec3		new_normal;

	textures[h->o->type](h, uv);
	if (h->o->material.mat_info & HAVE_BUMP)
	{
		bump_uv = get_pixel_xpm(h->o->material.bump_map, &h->texture);
		bump_uv = ft_mulv4f(bump_uv, 2.0f);
		bump_uv = ft_normv4(ft_subv4(bump_uv, ft_vec4(1, 1, 1, 0.0)));
		new_normal = ft_mulv3f(h->normal, bump_uv.b);
		new_normal = ft_addv3(new_normal, ft_mulv3f(uv[0], bump_uv.g));
		new_normal = ft_addv3(new_normal, ft_mulv3f(uv[1], bump_uv.r));
		h->normal = ft_normv3(new_normal);
	}
}

void	texture_sp(t_hit *h, t_vec3 *uv)
{
	t_vec3	n;

	n = h->normal;
	uv[0] = ft_cross(n, ft_vec3(!(n.z == 0.0), 0.0f, (n.z == 0.0)));
	uv[1] = ft_cross(n, uv[0]);
	h->texture.x = atan2f(n.x, n.z) / M_PI + 1.0f;
	h->texture.y = n.y * 0.5f + 0.5f;
}

void	texture_pl(t_hit *h, t_vec3 *uv)
{
	t_vec3	n;
	t_vec3	p;

	n = h->normal;
	p = ft_subv3(h->pos, h->o->obj.pl.p);
	uv[0] = ft_cross(n, ft_vec3(!(n.z == 0.0), 0.0f, (n.z == 0.0)));
	uv[1] = ft_cross(n, uv[0]);
	h->texture.x = fabsf(ft_dotv3(p, uv[0]));
	h->texture.y = fabsf(ft_dotv3(p, uv[1]));
}

void	texture_cy(t_hit *h, t_vec3 *uv)
{
	t_vec3	n;
	t_vec3	p;

	n = h->o->obj.cy.normal;
	p = ft_subv3(h->pos, h->o->obj.cy.center);
	uv[0] = ft_cross(n, ft_vec3(!(n.z == 0.0), 0.0f, (n.z == 0.0)));
	uv[1] = ft_cross(n, uv[0]);
	h->texture.x = 0.5f + atan2f(ft_dotv3(p, uv[1]), \
		ft_dotv3(p, uv[0])) / (2.0f * M_PI);
	h->texture.y = h->o->obj.cy.h - ft_dotv3(p, n);
	h->texture.y /= h->o->obj.cy.h;
}

void	texture_qd(t_hit *h, t_vec3 *uv)
{
	t_vec4		p;
	t_matrix4	w2obj;

	uv[0] = ft_vec3(1, 0, 0);
	uv[1] = ft_vec3(0, 1, 0);
	w2obj = get_invtransform(h->o->obj.qd.center, h->o->obj.qd.angles, \
		ft_vec3(1, 1, 1));
	p = ft_mulm4v(w2obj, ft_vec4(h->pos.x, h->pos.y, h->pos.z, 1.0f));
	h->texture.x = atan2f(p.z, p.x) / (2.0f * M_PI);
	h->texture.y = asinf(p.y) / M_PI;
}
