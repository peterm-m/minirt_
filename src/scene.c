
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
	if (!ft_strncmp(line, "A ", 2))
		parser_ambient(tokens, scene);
	else if (!ft_strncmp(line, "C ", 2))
		parser_camera(tokens, scene);
	else if (!ft_strncmp(line, "L ", 2))
		parser_light(tokens, scene);
	else if (!ft_strncmp(line, "sp ", 3))
		parser_sp(tokens, scene);
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
	i = -1;
	while (lines[++i])
		process_line(lines[i], scene);
	ft_iterarr((void **)lines, free);
	free(lines);
	if (!scene->c)
		ft_error("No camera");
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
		ft_error("Invalid number of argument");
	file_name = argv[1];
	len_file_name = ft_strlen(file_name);
	if (len_file_name < LEN_EXTENSION && \
		ft_strncmp(file_name + len_file_name - LEN_EXTENSION,
			EXTENSION, LEN_EXTENSION))
		ft_error("Invalid name");
	file_text = load_file(file_name);
	scene = process_file(file_text);
	free(file_text);
	return (scene);
}

void	delete_scene(t_scene *scene)
{
	free(scene->a);
	free(scene->l);
	free(scene->sp);
	free(scene->c);
	free(scene);
}
