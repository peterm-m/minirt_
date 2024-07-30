#ifndef MENU_H
# define MENU_H

# include "minirt.h"
# include <sys/param.h>

//menu
void	menu(t_render *r, t_ivec2 pixel);
int		exit_menu();
int     menu_ambient(t_render *r,t_hit h);

// change_obj.c
int		change(t_render *r, t_hit h);

//change_ambient.c
int     change_ambient(t_render *r);

// change_material.c
int     change_material(t_render *r, t_hit h);

// cli_object.c
void	cli_sp(t_object *o);
void	cli_pl(t_object *o);
void	cli_cy(t_object *o);
void	cli_qd(t_object *o);

void	cli_object(t_object *o);

// read.c
int     read_input(size_t size);
char	*read_param(size_t size);

#endif