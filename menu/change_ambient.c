/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:46 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/30 20:16:58 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	change_camera(t_render *r)
{
	int		j;
	char	*camera;

	printf (BHMAG"Camera:\nPosition: (%f,%f,%f)\nFile View: %f\nNormal: "
		"(%f,%f,%f)\n",
		r->scene->c->pos.x, r->scene->c->pos.y, r->scene->c->pos.z,
		r->scene->c->fov, r->scene->c->normal.x, r->scene->c->normal.y,
		r->scene->c->normal.z);
	printf(BHYEL"Enter the new Camera:\n"END);
	camera = read_param(50);
	j = o_parser_camera(ft_split(camera, ' '), r->scene->c);
	return (j);
}

int	change_ambient_l(t_render *r)
{
	int		j;
	char	*ambient;

	printf (BHMAG"Ambient Light:\nBright: %f\nColor: (%f,%f,%f)\n",
		r->scene->a->ratio, r->scene->a->rgba.x, r->scene->a->rgba.y,
		r->scene->a->rgba.z);
	printf(BHYEL"Enter the new Ambient Light:\n"END);
	ambient = read_param(50);
	j = o_parser_ambient(ft_split(ambient, ' '), r->scene->a);
	return (j);
}

int	change_lights(t_render *r)
{
	int		i;
	int		j;
	int		index;
	char	*light;

	i = -1;
	while (r->scene->l[++i])
	{
		printf (BHMAG"Light index: [%d]\nPosition: (%f,%f,%f)\nBright: %f\n"
			"Color: (%f,%f,%f)\n", i, r->scene->l[i]->pos.x,
			r->scene->l[i]->pos.y, r->scene->l[i]->pos.z, r->scene->l[i]->ratio,
			r->scene->l[i]->rgba.x, r->scene->l[i]->rgba.y,
			r->scene->l[i]->rgba.z);
	}
	printf("Select index: i = %d\n", i);
	index = read_input(5);
	if (index < 0 || index >= i)
		return (EXIT_FAILURE);
	printf(BHYEL"Enter the new Light:\n"END);
	light = read_param(50);
	j = o_parser_light(ft_split(light, ' '), r->scene->l[index]);
	return (j);
}

int	change_env(t_render *r)
{
	char	*file;
	t_xpm	*x;

	printf(BHMAG"Enter the Env xpm file:\n"END);
	file = read_param(100);
	x = ft_xpm_image(file);
	if (x == NULL)
		return (EXIT_FAILURE);
	if (r->env)
	{
		mlx_destroy_image(ft_getmlx(), r->env);
		free(r->env);
	}
	else
		r->env = x;
	return (EXIT_SUCCESS);
}

int	change_ambient(t_render *r)
{
	int	inp;

	printf(BHMAG"\n*** You are in Change Ambient Mode ***\nSelect which"
		" attribute you want to change:\n\n"BHRED"0. Exit\n"BHCYN"1. Lights\n"
		BHGRN"2. Camera\n"BHYEL"3. Ambient Light\n"BHBLU"4. Environ\n\n"END);
	inp = read_input(4);
	if (inp == 0)
		return (exit_menu());
	else if (inp == 1)
		return (change_lights(r));
	else if (inp == 2)
		return (change_camera(r));
	else if (inp == 3)
		return (change_ambient_l(r));
	else if (inp == 4)
		return (change_env(r));
	return (EXIT_FAILURE);
}
