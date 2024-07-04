/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   render.c                                                                 */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 13:57:48 by pedromar                                 */
/*   Updated: 2024/07/04 12:43:51 by pedromar                                 */
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

int	delete_render(t_render *render)
{
	mlx_loop_end(ft_getmlx());
	mlx_destroy_image(ft_getmlx(), render->canvas->im);
	mlx_destroy_window(ft_getmlx(), render->canvas->win);
	free(render->canvas);
	free(render->scene->a);
	free(render->scene->l);
	free(render->scene->sp);
	free(render->scene->c);
	free(render->scene);
	return (EXIT_SUCCESS);
}
