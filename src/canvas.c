/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   canvas.c                                                                 */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 13:57:48 by pedromar                                 */
/*   Updated: 2024/07/03 13:59:19 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

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
