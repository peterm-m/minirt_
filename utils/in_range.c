/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:10:37 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/07 16:06:47 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	in_range(float f, float upper_lim, float lower_lim)
{
	return (isfinite(f) && (isgreaterequal(f, lower_lim)
			&& islessequal(f, upper_lim)));
}
