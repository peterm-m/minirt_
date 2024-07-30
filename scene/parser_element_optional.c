/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_element_optional.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:08:49 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/30 16:24:40 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*     A             0.2        255,255,255
*    type    |     ratio     |   color
*  tokens[0] |   tokens[1]   |  tokens[2]
*/
#define N_TOKEN_AMBIENT 3

int	o_parser_ambient(char **tokens, t_scene *scene)
{
	if (scene->a)
		return(EXIT_FAILURE);
	if (ft_lenarr((void **)tokens) != N_TOKEN_AMBIENT)
		return(EXIT_FAILURE);
	scene->a = mallox(sizeof(t_ambient));
	scene->a->ratio = ft_atof(tokens[1]);
	if (!in_range(scene->a->ratio, 1.0f, 0.0f))
		return(EXIT_FAILURE);
	scene->a->rgba = parser_color(tokens[2]);
	scene->a->color = ft_mulv4f(scene->a->rgba, scene->a->ratio / 255.0f);
	return(EXIT_SUCCESS);
}

#define N_TOKEN_CAMERA 4

int	o_parser_camera(char **tokens, t_scene *scene)
{
	if (scene->c)
		return(EXIT_FAILURE);
	if (ft_lenarr((void **)tokens) != N_TOKEN_CAMERA)
		return(EXIT_FAILURE);
	scene->c = mallox(sizeof(t_camera));
	scene->c->pos = parser_vec3(tokens[1]);
	scene->c->normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(scene->c->normal), 0.0f))
		return(EXIT_FAILURE);
	if (islessgreater(ft_lenv3(scene->c->normal), 1.0f))
		printf("Warning: normal in camera was normalized\n");
	scene->c->normal = ft_normv3(scene->c->normal);
	scene->c->fov = ft_atof(tokens[3]);
	if (!in_range(scene->c->fov, 180.0f, 0.0f))
		return(EXIT_FAILURE);
	scene->c->fov = tan(scene->c->fov / 2.0f * M_PI / 180.0f);
	scene->c->cam_world = lookatl(\
		ft_subv3(scene->c->pos, scene->c->normal), \
		ft_vec3(0.0f, 1.0f, 0.0f), scene->c->pos);
	return(EXIT_SUCCESS);
}

#define N_TOKEN_LIGHT 5

int	o_parser_light(char **tokens, t_light *l)
{
	printf("tokens = %d\n", ft_lenarr((void **)tokens));
	if (ft_lenarr((void **)tokens) != N_TOKEN_LIGHT)
		return(printf("error1\n"), EXIT_FAILURE);
	l->pos = parser_vec3(tokens[1]);printf("bien1\n");
	l->ratio = ft_atof(tokens[2]);printf("bien2\n");
	if (!in_range(l->ratio, 1.0f, 0.0f))
		return(EXIT_FAILURE);
	l->rgba = parser_color(tokens[3]);printf("bien3\n");
	l->color = ft_mulv4f(l->rgba, l->ratio / 255.0f);printf("bie4n\n");
	printf("bien\n");
	return (EXIT_SUCCESS);
}
