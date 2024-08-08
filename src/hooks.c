/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:57:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/08 18:03:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	key_manager(int key, t_render *r)
{
	static int	index_c = 0;

	if (key == XK_Escape)
		mlx_loop_end(ft_getmlx());
	else if (key == XK_c)
	{
		index_c++;
		index_c *= (r->scene->cs[index_c] != NULL);
		r->scene->c = r->scene->cs[index_c];
		scene_to_cam(r->scene);
		printf("change to cam %d \n", index_c);
		log_camera(r->scene->c);
		mlx_loop_hook(ft_getmlx(), &render_loop, r);
	}
	return (EXIT_SUCCESS);
}

static int	mouse_manager(int button, int x, int y, void *p)
{
	t_render	*r;

	r = (t_render *)p;
	r->mouse.r_press[button].x = x;
	r->mouse.r_press[button].y = y;
	if (button == Button1)
		menu(r, r->mouse.r_press[button]);
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
