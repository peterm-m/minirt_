/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:08:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 18:42:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define N_TOKEN_SPHERE 4
#define N_TOKEN_PLANE 4
#define N_TOKEN_CYLINDER 6
#define N_TOKEN_CONE 6

static t_vec3	parser_sp(char **tokens, t_obj *o);
static t_vec3	parser_pl(char **tokens, t_obj *o);
static t_vec3	parser_cy(char **tokens, t_obj *o);
static t_vec3	parser_cn(char **tokens, t_obj *o);

void	parser_object(char **tokens, t_scene *scene, t_type_obj type)
{
	t_object		*obj;
	static int		n_tokens[4] = {\
		N_TOKEN_SPHERE,
		N_TOKEN_PLANE,
		N_TOKEN_CYLINDER,
		N_TOKEN_CONE};
	static t_vec3	(*parser[4])(char **, t_obj *) = {\
		parser_sp,
		parser_pl,
		parser_cy,
		parser_cn};

	if (ft_lenarr((void **)tokens) != n_tokens[type])
		ft_error("Invalid number of argument in object");
	obj = mallox(sizeof(t_object));
	obj->type = type;
	obj->color.rgb = parser[type](tokens, &obj->obj);
	obj->color.a = 0.0f;
	if (!valid_color(obj->color))
		ft_error("Invallid color in object");
	obj->color = ft_divv4f(obj->color, 255.0f);
	scene->o = (t_object **)ft_addarr((void **)scene->o, obj);
}

/*
*     sp       0.0,0.0,20.6      12.6     10,0,255
*    type    |    center    |  diameter |  color
*  tokens[0] |   tokens[1]  | tokens[2] | tokens[3]
*/

static t_vec3	parser_sp(char **tokens, t_obj *o)
{
	o->sp.center = parser_vec3(tokens[1]);
	o->sp.r = ft_atof(tokens[2]);
	if (!isfinite(o->sp.r) || islessequal(o->sp.r, 0.0f))
		ft_error("Invalid diameter in sphere");
	o->sp.r /= 2.0f;
	o->sp.r *= o->sp.r;
	return (parser_vec3(tokens[3]));
}

/*
*     pl       0.0,0.0,20.6    0.0,1.0,0.0  10,0,255
*    type    |    point     |    normal   |  color
*  tokens[0] |   tokens[1]  |   tokens[2] | tokens[3]
*/

static t_vec3	parser_pl(char **tokens, t_obj *o)
{
	o->pl.p = parser_vec3(tokens[1]);
	o->pl.normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(o->pl.normal), 0.0f))
		ft_error("Invalid normal in plane");
	if (islessgreater(ft_lenv3(o->pl.normal), 1.0f))
		printf("Warning: normal in plane was normalized\n");
	o->pl.normal = ft_normv3(o->pl.normal);
	return (parser_vec3(tokens[3]));
}

/*
 *    cy       50.0,0.0,20.6  0.0,0.0,1.0     14.2        21.42     10,0,255
*    type    |    center    |    normal   | diameter  |  height   |  color
*  tokens[0] |   tokens[1]  |   tokens[2] | tokens[3] | tokens[4] | tokens[5]
*/

static t_vec3	parser_cy(char **tokens, t_obj *o)
{
	o->cy.center = parser_vec3(tokens[1]);
	o->cy.normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(o->cy.normal), 0.0f))
		ft_error("Invalid normal in cylinder");
	if (islessgreater(ft_lenv3(o->cy.normal), 1.0f))
		printf("Warning: normal in cylinder was normalized\n");
	o->cy.normal = ft_normv3(o->cy.normal);
	o->cy.r = ft_atof(tokens[3]);
	if (!isfinite(o->cy.r) || islessequal(o->cy.r, 0.0f))
		ft_error("Invalid diameter in cylinder");
	o->cy.r /= 2.0f;
	o->cy.h = ft_atof(tokens[4]);
	if (!isfinite(o->cy.h) || islessequal(o->cy.h, 0.0f))
		ft_error("Invalid height in cylinder");
	return (parser_vec3(tokens[5]));
}

/*
 *    cn       50.0,0.0,20.6  0.0,0.0,1.0     14.2        21.42     10,0,255
*    type    |    center    |    normal   | diameter  |  height   |  color
*  tokens[0] |   tokens[1]  |   tokens[2] | tokens[3] | tokens[4] | tokens[5]
*/

static t_vec3	parser_cn(char **tokens, t_obj *o)
{
	o->cn.center = parser_vec3(tokens[1]);
	o->cn.normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(o->cn.normal), 0.0f))
		ft_error("Invalid normal in cone");
	if (islessgreater(ft_lenv3(o->cn.normal), 1.0f))
		printf("Warning: normal in cone was normalized\n");
	o->cn.normal = ft_normv3(o->cn.normal);
	o->cn.r = ft_atof(tokens[3]);
	if (!isfinite(o->cn.r) || islessequal(o->cn.r, 0.0f))
		ft_error("Invalid diameter in cone");
	o->cn.r /= 2.0f;
	o->cn.h = ft_atof(tokens[4]);
	if (!isfinite(o->cn.h) || islessequal(o->cn.h, 0.0f))
		ft_error("Invalid height in cone");
	return (parser_vec3(tokens[5]));
}
