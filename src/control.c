/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   control.c                                                                */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 13:57:13 by pedromar                                 */
/*   Updated: 2024/07/03 13:59:26 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	render_loop(void *r)
{
	(void) r;
	return (EXIT_SUCCESS);
}

int	key_manager(int key, t_canvas *canvas)
{
	if (key == XK_Escape)
		delete_canvas(canvas);
	return (EXIT_SUCCESS);
}

void	set_control(t_canvas *canvas)
{
	mlx_hook(canvas->win, 2, 1L << 0, &key_manager, canvas);
	mlx_hook(canvas->win, 3, 1L << 0L, &key_manager, canvas);
	mlx_hook(canvas->win, 17, 0L, &delete_canvas, canvas);
	mlx_loop_hook(ft_getmlx(), &render_loop, canvas);
}
