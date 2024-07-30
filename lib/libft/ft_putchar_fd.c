/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:54:10 by pedro             #+#    #+#             */
/*   Updated: 2024/07/30 11:37:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fildes)
{
	int	i;

	i = write(fildes, &c, 1);
	(void)i;
}

/*
** Outputs the char c to the file descriptor filedes.
*/