/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:31:43 by pedro             #+#    #+#             */
/*   Updated: 2024/05/21 11:59:10 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, nmemb * size);
	return ((void *)res);
}

/*
** Contiguously allocates enough space for nmemb objects that are size bytes
** of memory each and returns a pointer to the allocated memory.
** The allocated memory is filled with bytes of value zero.
*/
