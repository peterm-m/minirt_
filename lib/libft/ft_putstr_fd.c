/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:58:04 by pedro             #+#    #+#             */
/*   Updated: 2024/07/30 11:39:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int filedes)
{
	int	j;
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		j = write(filedes, &str[i], 1);
		i++;
	}
	(void)j;
}

/*
** Outputs the string str to the file descriptor filedes.
*/