/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mlx_wrappers.c                                                           */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/04 11:20:50 by pedromar                                 */
/*   Updated: 2024/07/04 12:31:53 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_getmlx(void)
{
	static void	*mlx;

	if (mlx == NULL)
		mlx = mlx_init();
	if (!mlx)
		ft_error("mlx error");
	return (mlx);
}

void	*ft_new_image(int w, int h)
{
	void	*ptr;

	ptr = mlx_new_image(ft_getmlx(), w, h);
	if (!ptr)
		ft_error("mlx error");
	return (ptr);
}

void	*ft_new_windows(int w, int h, char *name)
{
	void	*win;

	win = mlx_new_window(ft_getmlx(), w, h, name);
	if (!win)
		ft_error("mlx error");
	return (win);
}

void	ft_put_image_to_window(t_canvas *canvas)
{
	mlx_put_image_to_window(ft_getmlx(), canvas->win, canvas->im, 0, 0);
}

void	ft_put_pixel(t_canvas *can, int x, int y, int c)
{
	char	*dst;

	if (x > 0 && y > 0 && x < IM1_SX && y < IM1_SY)
	{
		dst = can->data + (y * can->sl + x * (can->bpp / 8));
		*(unsigned int *) dst = (unsigned int)c;
	}
}
