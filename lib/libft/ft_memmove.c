/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:50:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/21 11:40:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int			i;

	i = 0;
	if (((unsigned char *)dest) == NULL && ((unsigned char *)src) == NULL)
		return (NULL);
	if (((unsigned char *)src) < ((unsigned char *)dest))
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (((unsigned char *)dest));
}

/*
** Copies n bytes from string src to string dest.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
*/
