/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:57:07 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/29 20:49:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "scene.h"
# include "canvas.h"

# define WIN1_SX 1024
# define WIN1_SY 1024
# define IM1_SX 1024
# define IM1_SY 1024

# define NUM_BUTTON 5

typedef struct s_xpm	t_xpm;

typedef struct s_mevent
{
	t_ivec2	r_press[NUM_BUTTON];
	t_ivec2	r_release[NUM_BUTTON];
}	t_mevent;

typedef struct s_render
{
	t_canvas	*canvas;
	t_scene		*scene;
	t_mevent	mouse;
	t_xpm		*env;
}	t_render;

void	new_render(t_render	*render, int argc, char **argv);
void	delete_render(t_render *render);
void	config_hooks(t_render *render);

int		render_loop(t_render *r);

#endif // RENDER_H