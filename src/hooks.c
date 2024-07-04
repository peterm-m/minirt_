
#include "minirt.h"

static int	key_manager(int key, t_render *render)
{
	(void) render;
	if (key == XK_Escape)
		mlx_loop_end(ft_getmlx());
	return (EXIT_SUCCESS);
}

void	config_hooks(t_render *render)
{
	mlx_hook(render->canvas->win, 2, 1L << 0, &key_manager, render);
	mlx_hook(render->canvas->win, 3, 1L << 0L, &key_manager, render);
	mlx_hook(render->canvas->win, 17, 0L, &mlx_loop_end, ft_getmlx());
	mlx_loop_hook(ft_getmlx(), &render_loop, render);
}
