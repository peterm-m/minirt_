/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   control.c                                                                */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 13:57:13 by pedromar                                 */
/*   Updated: 2024/07/03 21:13:56 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	render_loop(t_render *r)
{
	(void) r;
	return (EXIT_SUCCESS);
}

int	key_manager(int key, t_render *render)
{
	if (key == XK_Escape)
		delete_canvas(render);
	return (EXIT_SUCCESS);
}

void	set_control(t_render *render)
{
	mlx_hook(render->canvas->win, 2, 1L << 0, &key_manager, render);
	mlx_hook(render->canvas->win, 3, 1L << 0L, &key_manager, render);
	mlx_hook(render->canvas->win, 17, 0L, &delete_canvas, render);
	mlx_loop_hook(ft_getmlx(), &render_loop, render);
}
