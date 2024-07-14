/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:30:41 by pedro             #+#    #+#             */
/*   Updated: 2024/05/21 11:40:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		ini;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	ini = 0;
	end = (int)ft_strlen((char *)s1);
	while (s1[ini] && ft_setcheck(s1[ini], set))
		ini++;
	while (end > ini && ft_setcheck(s1[end - 1], set))
		end--;
	res = (char *)malloc(sizeof(char) * (end - ini + 1));
	if (!res)
		return (NULL);
	while (ini < end)
		res[i++] = s1[ini++];
	res[i] = '\0';
	return (res);
}

/*
** Allocates with malloc(), and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string.
** Will be considered as whitespaces the following characters ’ ’, ’\n’,
** and ’\t’. If s has no whites- paces at the beginning or at the end,
** the function returns a copy of s.
** If the allocation fails the function returns NULL.
*/