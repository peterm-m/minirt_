/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser_scene.c                                                           */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 14:33:08 by pedromar                                 */
/*   Updated: 2024/07/04 12:49:33 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>
#include <fcntl.h>

#define SIZE_DUMMY_BUF	4056

ssize_t	len_file(char *file_name)
{
	char	dummy_buf[SIZE_DUMMY_BUF];
	ssize_t	aux;
	ssize_t	len_file;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error open file");
	len_file = 0;
	aux = 1;
	while (aux > 0)
	{
		aux = read(fd, dummy_buf, SIZE_DUMMY_BUF);
		if (aux > 0)
			len_file += aux;
	}
	close(fd);
	return (len_file);
}

#undef SIZE_DUMMY_BUF

char	*load_file(char *file_name)
{
	char	*file_text;
	ssize_t	file_size;
	int		fd;

	file_size = len_file(file_name);
	file_text = mallox(sizeof(char) * (file_size + 1));
	file_text[file_size] = '\0';
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error open file");
	if (read(fd, file_text, file_size +1) != file_size)
		ft_error("Error load file");
	close(fd);
	return (file_text);
}

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

#define EXTENSION	".rt"
#define LEN_EXTENSION	3

t_scene	*parser_scene(int argc, char **argv)
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

#undef EXTENSION
#undef LEN_EXTENSION
