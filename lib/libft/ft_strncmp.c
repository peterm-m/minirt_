/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:35:33 by pedro             #+#    #+#             */
/*   Updated: 2024/06/18 11:58:13 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n != 0)
	{
		while (--n && (*ss1 || *ss2))
		{
			if (*ss1 != *ss2)
				return (*ss1 - *ss2);
			ss1++;
			ss2++;
		}
		return (*ss1 - *ss2);
	}
	return (0);
}

/*
** compares not more than n characters of the
** null-terminated strings s1 and s2.  characters that appear after a `\0'
** character are not compared.
*/
