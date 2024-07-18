
#include "minirt.h"

t_canvas	*new_canvas(void)
{
	t_canvas	*canvas;

	canvas = mallox(sizeof(t_canvas));
	canvas->mlx = ft_getmlx();
	canvas->win = ft_new_windows(WIN1_SX, WIN1_SY, "miniRT");
	canvas->im = ft_new_image(IM1_SX, IM1_SY);
	canvas->data = mlx_get_data_addr(canvas->im, &canvas->bpp,
			&canvas->sl, &canvas->endian);
	return (canvas);
}

void	delete_canvas(t_canvas *canvas)
{
	mlx_destroy_image(ft_getmlx(), canvas->im);
	mlx_destroy_window(ft_getmlx(), canvas->win);
	free(canvas);
}

void	put_pixel(t_canvas *can, t_ivec2 *pix, int c)
{
	char	*dst;

	dst = can->data + (pix->y * can->sl + pix->x * (can->bpp / 8));
	*(unsigned int *) dst = (unsigned int)c;
}

void	canvas_to_window(t_canvas *canvas)
{
	mlx_put_image_to_window(ft_getmlx(), canvas->win, canvas->im, 0, 0);
}
