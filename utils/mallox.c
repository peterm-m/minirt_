/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:03:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:03:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*mallox(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		ft_error("malloc error");
	return (new);
}
