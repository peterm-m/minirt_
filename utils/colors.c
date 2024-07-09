/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 16:41:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// https://www.fourmilab.ch/documents/specrend/specrend.c

int	rgba_to_int(t_vec4 c)
{
	return (*(int *)(unsigned char [4]){\
		(unsigned char)(MAX_RGB * c.b), \
		(unsigned char)(MAX_RGB * c.g), \
		(unsigned char)(MAX_RGB * c.r), \
		(unsigned char)(MAX_RGB * c.a)});
}

t_vec4	int_to_rgba(int color)
{
	t_vec4	c;

	c.a = (float)(((unsigned char *)&color)[3]);
	c.r = (float)(((unsigned char *)&color)[2]);
	c.g = (float)(((unsigned char *)&color)[1]);
	c.b = (float)(((unsigned char *)&color)[0]);
	return (c);
}

int	valid_color(t_vec4 c)
{
	return (in_range(c.a, 255.0f, 0.0f) && \
		in_range(c.r, 255.0f, 0.0f) && \
		in_range(c.g, 255.0f, 0.0f) && \
		in_range(c.b, 255.0f, 0.0f));
}
