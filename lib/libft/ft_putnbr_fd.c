/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:27:19 by pedro             #+#    #+#             */
/*   Updated: 2024/05/21 11:45:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int filedes)
{
	char	c;

	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", filedes);
	else
	{
		if (nb < 0)
		{
			write(filedes, "-", 1);
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_putnbr_fd(nb / 10, filedes);
			ft_putnbr_fd(nb % 10, filedes);
		}
		else
		{
			c = '0' + nb;
			write(filedes, &c, 1);
		}
	}
}
/*
** Outputs the integer n to the file descriptor fd.
*/
