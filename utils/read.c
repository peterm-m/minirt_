/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:57:49 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 18:58:13 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*read_input(size_t size)
{
	char	*buf;
	int		readed;

	buf = mallox(size + 1);
	if (!buf)
		return (NULL);
	readed = read(0, buf, size - 1);
	if (readed < 0)
		return (NULL);
	buf[readed] = '\0';
	return (buf);
}
