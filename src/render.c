/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:57:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/13 16:44:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	new_render(t_render	*render, int argc, char **argv)
{
	render->scene = new_scene(argc, argv);
	//transform_scene(&render->scene->c->cam_world, render->scene);
	render->canvas = new_canvas();
}

void	delete_render(t_render *render)
{
	delete_canvas(render->canvas);
	delete_scene(render->scene);
}
