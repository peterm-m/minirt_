/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:04:59 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:05:00 by pedromar         ###   ########.fr       */
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
	else if (!ft_strncmp(tokens[0], "cn", 3))
		parser_object(tokens, scene, obj_cone);
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
	i = -1;
	while (lines[++i])
		process_line(lines[i], scene);
	ft_iterarr((void **)lines, free);
	free(lines);
	if (!scene->c)
		ft_error("No camera");
	if (!scene->a && !scene->l)
		ft_error("No lights"); //TODO: No error default ambient light
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
	free(file_text);
	return (scene);
}

void	delete_scene(t_scene *scene)
{
	free(scene->a);
	ft_iterarr((void **)scene->l, free);
	free(scene->l);
	ft_iterarr((void **)scene->o, free);
	free(scene->o);
	free(scene->c);
	free(scene);
}
