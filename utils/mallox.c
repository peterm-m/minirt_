/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:11:22 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/06 18:07:22 by pedromar         ###   ########.fr       */
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
