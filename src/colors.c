/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   colors.c                                                                 */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/20 15:21:35 by pedromar                                 */
/*   Updated: 2024/07/03 20:09:58 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// https://www.fourmilab.ch/documents/specrend/specrend.c

#define MAX_RGB 255

int	set_rgba(t_vec4 c)
{
	return (((int)(MAX_RGB * c.b)) \
		+ ((int)(MAX_RGB * c.g) << 8) \
		+ ((int)(MAX_RGB * c.r) << 16) \
		+ ((int)(MAX_RGB * c.a) << 24));
}

t_vec4	get_rgba(float color)
{
	t_vec4	c;

	c.r = (((unsigned int)color >> 16) & 0xFF);
	c.g = (((unsigned int)color >> 8) & 0xFF);
	c.b = (((unsigned int)color) & 0xFF);
	c.a = 0.0f;
	return (c);
}

int	valid_color(t_vec4 c)
{
	return ((isgreaterequal(c.a, 0.0f) && islessequal(c.a, 255.0f)) \
		&& (isgreaterequal(c.r, 0.0f) && islessequal(c.r, 255.0f)) \
		&& (isgreaterequal(c.g, 0.0f) && islessequal(c.g, 255.0f)) \
		&& (isgreaterequal(c.b, 0.0f) && islessequal(c.b, 255.0f)));
}
