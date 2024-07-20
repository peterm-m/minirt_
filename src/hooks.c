/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:57:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 14:59:33 by pedromar         ###   ########.fr       */
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

static int	mouse_manager(int button, int x, int y, void *p)
{
	t_render	*r;
	t_ivec2		pixel;

	r = (t_render *)p;
	pixel.x = x;
	pixel.y = y;
	if (button == Button1)
		log_render(r, pixel);
	if (button == Button2)
		mlx_loop_hook(ft_getmlx(), &render_loop, r);
	return (EXIT_SUCCESS);
}

void	config_hooks(t_render *render)
{
	void	*c;

	c = render->canvas->win;
	mlx_hook(c, KeyPress, KeyPressMask, &key_manager, render);
	mlx_hook(c, KeyRelease, KeyPressMask, &key_manager, render);
	mlx_hook(c, ButtonPress, ButtonPressMask, mouse_manager, render);
	mlx_hook(c, DestroyNotify, NoEventMask, &mlx_loop_end, ft_getmlx());
	mlx_loop_hook(ft_getmlx(), &render_loop, render);
}
