/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:24:41 by pedro             #+#    #+#             */
/*   Updated: 2024/07/30 11:38:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int filedes)
{
	int	j;
	int	i;

	i = 0;
	if (str == NULL || filedes < 0)
		return ;
	while (str[i] != '\0')
	{
		j = write(filedes, &str[i], 1);
		i++;
	}
	j = write(filedes, "\n", 1);
	(void) j;
}

/*
** Outputs the string s to the file descriptor fd followed by a ’\n’.
*/