/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:57:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 21:45:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	key_manager(int key, t_render *render)
{
	(void) render;
	if (key == XK_Escape)
		mlx_loop_end(ft_getmlx());
	return (EXIT_SUCCESS);
}

static int	mouse_manager(int button,int x,int y, void *p)
{
	t_render	*r;
	t_ivec2		pixel;

	r = (t_render *)p;
	pixel.x = x;
	pixel.y = y;
	if (button == 1)
		log_render(r, pixel);
	return (EXIT_SUCCESS);
}

void	config_hooks(t_render *render)
{
	mlx_hook(render->canvas->win, 2, 1L << 0, &key_manager, render);
	mlx_hook(render->canvas->win, 3, 1L << 0L, &key_manager, render);
	mlx_mouse_hook(render->canvas->win, mouse_manager, render);
	mlx_hook(render->canvas->win, 17, 0L, &mlx_loop_end, ft_getmlx());
	mlx_loop_hook(ft_getmlx(), &render_loop, render);
}
