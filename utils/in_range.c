/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:02:33 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:02:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	in_range(float f, float upper_lim, float lower_lim)
{
	return (isfinite(f) && (isgreaterequal(f, lower_lim)
			&& islessequal(f, upper_lim)));
}
