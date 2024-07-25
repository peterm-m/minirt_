/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:57:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/25 14:16:48 by pedromar         ###   ########.fr       */
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

	r = (t_render *)p;
	r->mouse.r_press[button].x = x;
	r->mouse.r_press[button].y = y;
	if (button == Button3)
		log_render(r, r->mouse.r_press[button]);
	else if (button == Button2)
		mlx_loop_hook(ft_getmlx(), &render_loop, r);
	else if (button == Button1)
		menu(r, r->mouse.r_press[button]);
	return (EXIT_SUCCESS);
}

static int	aux(int button, int x, int y, void *p)
{
	t_render	*r;

	r = (t_render *)p;
	r->mouse.r_release[button].x = x;
	r->mouse.r_release[button].y = y;
	printf("->button %d displazament x %d displazament y %d \n", button, r->mouse.r_press[button].x - r->mouse.r_release[button].x,  r->mouse.r_press[button].y - r->mouse.r_release[button].y);
	return (0);
}

void	config_hooks(t_render *render)
{
	void	*c;
	
	c = render->canvas->win;
	mlx_hook(c, ButtonRelease, ButtonReleaseMask, &aux, render);
	mlx_hook(c, KeyPress, KeyPressMask, &key_manager, render);
	mlx_hook(c, KeyRelease, KeyPressMask, &key_manager, render);
	mlx_hook(c, ButtonPress, ButtonPressMask, mouse_manager, render);
	mlx_hook(c, DestroyNotify, NoEventMask, &mlx_loop_end, ft_getmlx());
	mlx_loop_hook(ft_getmlx(), &render_loop, render);
}
