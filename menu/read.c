/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:57:49 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 16:26:24 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	get_menu_number(char *num)
{
	int	i;

	i = 0;
	while ((num[i]))
	{
		if (ft_isdigit(num[i]) || num[i] == 10)
			i++;
		else
			return (-1);
	}
	return (ft_atoi(num));
}

int	read_input(size_t size)
{
	char	*buf;
	int		readed;
	int		num;

	buf = mallox(size + 1);
	if (!buf)
		return (-1);
	readed = read(0, buf, size - 1);
	if (readed < 0)
		return (-1);
	buf[readed] = '\0';
	num = get_menu_number(buf);
	free(buf);
	return (num);
}

char	*read_param(size_t size)
{
	char	*buf;
	int		readed;

	buf = mallox(size + 1);
	if (!buf)
		return (NULL);
	readed = read(0, buf, size - 1);
	if (readed < 0)
		return (NULL);
	buf[readed -1] = '\0';
	return (buf);
}
