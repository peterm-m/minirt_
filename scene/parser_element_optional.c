/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_element_optional.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:08:49 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/08/08 20:28:18 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*     A             0.2        255,255,255
*    type    |     ratio     |   color
*  tokens[0] |   tokens[1]   |  tokens[2]
*/
#define N_TOKEN_AMBIENT 3

int	o_parser_ambient(char **tokens, t_ambient *a)
{
	int	i;

	if (ft_lenarr((void **)tokens) != N_TOKEN_AMBIENT)
		return (EXIT_FAILURE);
	a->ratio = ft_atof(tokens[1]);
	if (!in_range(a->ratio, 1.0f, 0.0f))
		return (EXIT_FAILURE);
	i = oparser_color(tokens[2], &a->rgba);
	a->color = ft_mulv4f(a->rgba, a->ratio / 255.0f);
	return (i);
}

#define N_TOKEN_CAMERA 4

int	o_parser_camera(char **tokens, t_camera *c)
{
	int	i;

	if (ft_lenarr((void **)tokens) != N_TOKEN_CAMERA)
		return (EXIT_FAILURE);
	i = oparser_vec3(tokens[1], &c->pos);
	i = oparser_vec3(tokens[2], &c->normal);
	if (!islessgreater(ft_lenv3(c->normal), 0.0f))
		return (EXIT_FAILURE);
	if (islessgreater(ft_lenv3(c->normal), 1.0f))
		printf("Warning: normal in camera was normalized\n");
	c->normal = ft_normv3(c->normal);
	c->fov = ft_atof(tokens[3]);
	if (!in_range(c->fov, 180.0f, 0.0f))
		return (EXIT_FAILURE);
	c->fov = tan(c->fov / 2.0f * M_PI / 180.0f);
	c->cam_world = lookatl(\
		ft_subv3(c->pos, c->normal), \
		ft_vec3(0.0f, 1.0f, 0.0f), c->pos);
	return (i);
}

#define N_TOKEN_LIGHT 4

int	o_parser_light(char **tokens, t_light *l)
{
	int	i;

	if (ft_lenarr((void **)tokens) != N_TOKEN_LIGHT)
		return (EXIT_FAILURE);
	i = oparser_vec3(tokens[1], &l->pos);
	l->ratio = ft_atof(tokens[2]);
	if (!in_range(l->ratio, 1.0f, 0.0f))
		return (EXIT_FAILURE);
	i = oparser_color(tokens[3], &l->rgba);
	l->color = ft_mulv4f(l->rgba, l->ratio / 255.0f);
	return (i);
}

int	oparser_qd(char **tokens, t_object *o)
{
	t_matrix4	w2obj;

	o->obj.qd.type = ft_atoi(tokens[1]);
	if (!(o->obj.qd.type > -1 && o->obj.qd.type < 4))
		return (EXIT_FAILURE);
	o->obj.qd.coef = mparser_vec3(tokens[2]);
	o->obj.qd.center = mparser_vec3(tokens[3]);
	o->obj.qd.angles = mparser_vec3(tokens[4]);
	o->obj.qd.bound_body.p_min = mparser_vec3(tokens[5]);
	o->obj.qd.bound_body.p_max = mparser_vec3(tokens[6]);
	o->obj.qd.a = ft_mat4();
	o->obj.qd.a.elements[0][0] = o->obj.qd.coef.x;
	o->obj.qd.a.elements[2][2] = o->obj.qd.coef.z;
	o->obj.qd.a.elements[1][1] = o->obj.qd.coef.y * (o->obj.qd.type != 3);
	o->obj.qd.a.elements[1][3] = o->obj.qd.coef.y / 2.0f * \
	(o->obj.qd.type == 3);
	o->obj.qd.a.elements[3][1] = o->obj.qd.a.elements[1][3];
	o->obj.qd.a.elements[3][3] = (o->obj.qd.type == 0) - (o->obj.qd.type == 2);
	w2obj = get_invtransform(o->obj.qd.center, o->obj.qd.angles, \
	ft_vec3(1, 1, 1));
	o->obj.qd.a = ft_mulm4m(w2obj, ft_mulm4m(o->obj.qd.a, \
	ft_transposem4(w2obj)));
	return (EXIT_SUCCESS);
}
