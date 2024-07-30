/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:39:15 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 19:20:32 by adiaz-uf         ###   ########.fr       */
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
}
