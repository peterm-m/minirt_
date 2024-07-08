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
