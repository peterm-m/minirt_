
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
	return (in_range(c.a, 255.0f, 0.0f) && \
		in_range(c.r, 255.0f, 0.0f) && \
		in_range(c.g, 255.0f, 0.0f) && \
		in_range(c.b, 255.0f, 0.0f));
}
