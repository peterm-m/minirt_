/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:27:38 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 16:42:19 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec4	rgba_negative(t_vec4 rgba)
{
	return (ft_vec4(1.0f - rgba.x, 1.0f - rgba.y, 1.0f - rgba.z, rgba.w));
}

t_vec4	rgba_grayscale(t_vec4 rgba)
{
	float	gray;

	gray = rgba.r * 0.2126f + rgba.g * 0.7152f + rgba.b * 0.0722f;
	return (ft_vec4(gray, gray, gray, rgba.w));
}

t_vec4	rgba_brightness(t_vec4 rgba, float brightness)
{
	float	factor;

	factor = MIN(brightness, 1.0f);
	return (ft_mulv4f(rgba, factor));
}

void	rgba_sum(t_vec4 *color, t_vec4 to_add, float brightness)
{
	t_vec4	aux;

	aux = rgba_brightness(to_add, brightness);
	color->x = MIN(color->x + aux.x, 1.0f);
	color->y = MIN(color->y + aux.y, 1.0f);
	color->z = MIN(color->z + aux.z, 1.0f);
	color->w = MIN(color->w + aux.w, 1.0f);
}
