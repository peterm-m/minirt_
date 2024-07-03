/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:03:07 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/21 12:12:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux_cat_strnjoin(char *dest, char *end, const char *str)
{
	while (dest < end && *str)
		*dest++ = *str++;
	return (dest);
}

size_t	ft_strnjoin(char *out, size_t out_size,
	const char *delim, char **chararr)
{
	char	*ptr;
	char	*strend;

	ptr = out;
	strend = out + out_size;
	while (ptr < strend && *chararr)
	{
		ptr = aux_cat_strnjoin(ptr, strend, *chararr);
		chararr++;
		if (*chararr)
			ptr = aux_cat_strnjoin(ptr, strend, delim);
	}
	return (ptr - out);
}
