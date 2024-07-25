/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/25 19:39:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// https://www.fourmilab.ch/documents/specrend/specrend.c

int	rgba_to_int(t_vec4 c)
{
	return (*(int *)(unsigned char [4]){\
		(unsigned char)(MAX_RGB * pow(c.b, 1 / 2.2f) + 0.5f), \
		(unsigned char)(MAX_RGB * pow(c.g, 1 / 2.2f) + 0.5f), \
		(unsigned char)(MAX_RGB * pow(c.r, 1 / 2.2f) + 0.5f), \
		(unsigned char)(MAX_RGB * pow(c.a, 1 / 2.2f) + 0.5f)});
}

t_vec4	int_to_rgba(int color)
{
	t_vec4	c;

	c.a = (float)(((unsigned char *)&color)[3]) / 255.0f;
	c.r = (float)(((unsigned char *)&color)[2]) / 255.0f;
	c.g = (float)(((unsigned char *)&color)[1]) / 255.0f;
	c.b = (float)(((unsigned char *)&color)[0]) / 255.0f;
	return (c);
}

int	valid_color(t_vec4 c)
{
	return (in_range(c.a, 255.0f, 0.0f) && \
		in_range(c.r, 255.0f, 0.0f) && \
		in_range(c.g, 255.0f, 0.0f) && \
		in_range(c.b, 255.0f, 0.0f));
}
