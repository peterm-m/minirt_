/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:22:39 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/06 18:08:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_lenarr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_iterarr(void **arr, void (*f)(void *))
{
	int	i;

	i = -1;
	while (arr[++i])
		f(arr[i]);
}

void	**ft_addarr(void **arr, void *data)
{
	int		len;
	void	**new_arr;

	len = ft_lenarr(arr);
	new_arr = (void **) mallox(sizeof(void *) * (len + 2));
	ft_memcpy(new_arr, arr, sizeof(void *) * (len + 1));
	new_arr[len] = data;
	new_arr[len + 1] = NULL;
	free(arr);
	return (new_arr);
}

void	**ft_newarr(void)
{
	void	**new_arr;

	new_arr = (void **) mallox(sizeof(void *));
	new_arr[0] = NULL;
	return (new_arr);
}
