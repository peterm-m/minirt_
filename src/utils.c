
#include "minirt.h"

void	ft_error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	*mallox(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		ft_error("malloc error");
	return (new);
}

int	in_range(float f, float upper_lim, float lower_lim)
{
	return (isfinite(f) && (isgreaterequal(f, lower_lim)
			&& islessequal(f, upper_lim)));
}

#define SIZE_DUMMY_BUF 4056

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
