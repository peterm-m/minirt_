
#include "minirt.h"

static int	render_trace(t_render *r, int x, int y)
{
	t_sp	*objects;

	objects = r->scene->sp;
	(void)objects;
	put_pixel(r->canvas, x, y, 0x00FF0000);
	return (EXIT_SUCCESS);
}

int	render_loop(t_render *r)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN1_SX)
	{
		y = -1;
		while (++y < WIN1_SY)
		{
			render_trace(r, x, y);
		}
	}
	canvas_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
