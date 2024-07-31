/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:04:59 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 19:23:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>
#include <fcntl.h>

#define EXTENSION	".rt"
#define LEN_EXTENSION	3

void	process_line(char *line, t_scene *scene)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		ft_error("malloc error");
	if (!ft_strncmp(tokens[0], "A", 2))
		parser_ambient(tokens, scene);
	else if (!ft_strncmp(tokens[0], "C", 2))
		parser_camera(tokens, scene);
	else if (!ft_strncmp(tokens[0], "L", 2))
		parser_light(tokens, scene);
	else if (!ft_strncmp(tokens[0], "sp", 3))
		parser_object(tokens, scene, obj_sphere);
	else if (!ft_strncmp(tokens[0], "pl", 3))
		parser_object(tokens, scene, obj_plane);
	else if (!ft_strncmp(tokens[0], "cy", 3))
		parser_object(tokens, scene, obj_cylinder);
	else if (!ft_strncmp(tokens[0], "qd", 3))
		parser_object(tokens, scene, obj_quadric);
	else
		ft_error("Error");
	ft_iterarr((void **)tokens, free);
	free(tokens);
}

t_scene	*process_file(char *file_text)
{
	t_scene	*scene;
	int		i;
	char	**lines;

	lines = ft_split(file_text, '\n');
	if (!lines)
		ft_error("Parser error");
	scene = mallox(sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	scene->l = (t_light **)ft_newarr();
	scene->o = (t_object **)ft_newarr();
	scene->cs = (t_camera **)ft_newarr();
	i = -1;
	while (lines[++i])
		process_line(lines[i], scene);
	ft_iterarr((void **)lines, free);
	free(lines);
	if (!scene->cs[0])
		ft_error("No camera");
	else
		scene->c = scene->cs[0];
	if (!scene->a && !scene->l)
		ft_error("No lights");
	return (scene);
}

t_scene	*new_scene(int argc, char **argv)
{
	size_t	len_file_name;
	char	*file_name;
	char	*file_text;
	t_scene	*scene;

	if (argc != 2)
		ft_error("usage: miniRT file_scene.rt");
	file_name = argv[1];
	len_file_name = ft_strlen(file_name);
	if (len_file_name < LEN_EXTENSION && \
		ft_strncmp(file_name + len_file_name - LEN_EXTENSION,
			EXTENSION, LEN_EXTENSION))
		ft_error("Invalid name: mandatory extension \".rt\"");
	file_text = load_file(file_name);
	scene = process_file(file_text);
	for (int  i = 0; scene->l[i]; i++) {
		scene->l[i]->pos.x -= scene->c->pos.x ;
		scene->l[i]->pos.y -= scene->c->pos.y;
		scene->l[i]->pos.z -= scene->c->pos.z ;
	}
	for (int  i = 0; scene->o[i]; i++) {
		if (scene->o[i]->type == obj_cylinder) { 
		scene->o[i]->obj.cy.center.x -= scene->c->pos.x;
		scene->o[i]->obj.cy.center.y -= scene->c->pos.y;
		scene->o[i]->obj.cy.center.z -= scene->c->pos.z;
		}
		else if (scene->o[i]->type == obj_sphere) {
		scene->o[i]->obj.sp.center.x -= scene->c->pos.x;
		scene->o[i]->obj.sp.center.y -= scene->c->pos.y;
		scene->o[i]->obj.sp.center.z -= scene->c->pos.z;
		}
		else if (scene->o[i]->type == obj_plane) {
		scene->o[i]->obj.pl.p.x -= scene->c->pos.x;
		scene->o[i]->obj.pl.p.y -= scene->c->pos.y;
		scene->o[i]->obj.pl.p.z -= scene->c->pos.z;
		scene->o[i]->obj.pl.n_dot_p = ft_dotv3(scene->o[i]->obj.pl.p, scene->o[i]->obj.pl.normal);
		}
		bound_object(scene->o[i]);
	}
	free(file_text);
	return (scene);
}

void	delete_obj(void *o)
{
	t_object	*obj;

	obj = (t_object *)o;
	if (obj->material.bump_map)
	{
		mlx_destroy_image(ft_getmlx(), obj->material.bump_map->im);
		free(obj->material.bump_map);
	}
	if (obj->material.texture)
	{
		mlx_destroy_image(ft_getmlx(), obj->material.texture->im);
		free(obj->material.texture);
	}
	free(obj);
}

void	delete_scene(t_scene *scene)
{
	free(scene->a);
	ft_iterarr((void **)scene->l, free);
	free(scene->l);
	ft_iterarr((void **)scene->o, delete_obj);
	free(scene->o);
	ft_iterarr((void **)scene->cs, free);
	free(scene->cs);
	free(scene);
}
