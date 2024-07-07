/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:27:38 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/07 22:58:47 by pedromar         ###   ########.fr       */
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

t_vec4	rgba_sum(t_vec4 rgba1, t_vec4 rgba2)
{
	return (ft_vec4(
			MIN(rgba1.r + rgba1.r, 1.0f),
			MIN(rgba1.g + rgba1.g, 1.0f),
			MIN(rgba1.b + rgba1.b, 1.0f),
			MIN(rgba1.a + rgba1.a, 1.0f)));
}
