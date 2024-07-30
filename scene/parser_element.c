/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:05:31 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 16:26:35 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*     A             0.2        255,255,255
*    type    |     ratio     |   color
*  tokens[0] |   tokens[1]   |  tokens[2]
*/
#define N_TOKEN_AMBIENT 3

void	parser_ambient(char **tokens, t_scene *scene)
{
	if (scene->a)
		ft_error("Multiple ambient lights");
	if (ft_lenarr((void **)tokens) != N_TOKEN_AMBIENT)
		ft_error("Invalid number of parameter in ambient light");
	scene->a = mallox(sizeof(t_ambient));
	scene->a->ratio = ft_atof(tokens[1]);
	if (!in_range(scene->a->ratio, 1.0f, 0.0f))
		ft_error("ambient lights with ratio out of range");
	scene->a->rgba = mparser_color(tokens[2]);
	scene->a->color = ft_mulv4f(scene->a->rgba, scene->a->ratio / 255.0f);
}

/*
*     C         -50.0,0,20       0,0,1       70
*    type    |     pos       |  normal   |  fov
*  tokens[0] |   tokens[1]   | tokens[2] | tokens[3]
*/
#define N_TOKEN_CAMERA 4

void	parser_camera(char **tokens, t_scene *scene)
{
	if (scene->c)
		ft_error("Multiple cameras");
	if (ft_lenarr((void **)tokens) != N_TOKEN_CAMERA)
		ft_error("Invalid number of parameter in camera");
	scene->c = mallox(sizeof(t_camera));
	scene->c->pos = mparser_vec3(tokens[1]);
	scene->c->normal = mparser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(scene->c->normal), 0.0f))
		ft_error("Invalid normal in camera");
	if (islessgreater(ft_lenv3(scene->c->normal), 1.0f))
		printf("Warning: normal in camera was normalized\n");
	scene->c->normal = ft_normv3(scene->c->normal);
	scene->c->fov = ft_atof(tokens[3]);
	if (!in_range(scene->c->fov, 180.0f, 0.0f))
		ft_error("Invalid fov in camera");
	scene->c->fov = tan(scene->c->fov / 2.0f * M_PI / 180.0f);
	scene->c->cam_world = lookatl(\
		ft_subv3(scene->c->pos, scene->c->normal), \
		ft_vec3(0.0f, 1.0f, 0.0f), scene->c->pos);
}

/*
*     L        -40.0,50.0,0.0     0.6       0,0,255
*    type    |      pos       |  ratio    |  color
*  tokens[0] |    tokens[1]   | tokens[2] | tokens[3]
*/
#define N_TOKEN_LIGHT 4

void	parser_light(char **tokens, t_scene *scene)
{
	t_light	*l;

	if (ft_lenarr((void **)tokens) != N_TOKEN_LIGHT)
		ft_error("Invalid number of argument in light");
	l = mallox(sizeof(t_light));
	l->pos = mparser_vec3(tokens[1]);
	l->ratio = ft_atof(tokens[2]);
	if (!in_range(l->ratio, 1.0f, 0.0f))
		ft_error("lights with ratio out of range");
	l->rgba = mparser_color(tokens[3]);
	l->color = ft_mulv4f(l->rgba, l->ratio / 255.0f);
	scene->l = (t_light **)ft_addarr((void **)scene->l, l);
}
