/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:04:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/06 18:07:19 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
