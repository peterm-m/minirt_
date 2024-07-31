/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:39:15 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 13:21:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	new_render(t_render	*render, int argc, char **argv)
{
	render->scene = new_scene(argc, argv);
	render->canvas = new_canvas();
	render->env = NULL;
}

void	delete_render(t_render *render)
{
	delete_canvas(render->canvas);
	delete_scene(render->scene);
	if (render->env)
	{
		mlx_destroy_image(ft_getmlx(), render->env->im);
		free(render->env);
	}
}
