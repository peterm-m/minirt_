/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:27:32 by pedro             #+#    #+#             */
/*   Updated: 2024/05/21 11:40:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lennb(int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len += 1;
	while (nb)
	{
		nb /= 10;
		len += 1;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	size_t	i;
	size_t	n_size;
	char	*str;

	i = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	n_size = ft_lennb(nb);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!str)
		return (NULL);
	str[n_size] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/*
** Takes an int, and converts it to a null-terminated string.
*/