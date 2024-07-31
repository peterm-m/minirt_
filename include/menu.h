/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:19:47 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 14:21:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "minirt.h"
# include <sys/param.h>

//menu
void	menu(t_render *r, t_ivec2 pixel);
int		exit_menu(void);
int		menu_ambient(t_render *r, t_hit h);

// change_obj.c
int		change(t_render *r, t_hit h);

//change_ambient.c
int		change_ambient(t_render *r);

// change_material.c
int		change_material(t_hit h);

int		change_texture(t_hit h);
int		change_bump(t_hit h);
int		change_gls(t_hit h);
int		change_pattern(t_hit h);

// cli_object.c
void	cli_sp(t_object *o);
void	cli_pl(t_object *o);
void	cli_cy(t_object *o);
void	cli_qd(t_object *o);

void	cli_object(t_object *o);

// read.c
int		read_input(size_t size);
char	*read_param(size_t size);

#endif