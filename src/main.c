/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:01:42 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 14:25:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_render	render;

	printf("miniRT %s %s\n", __DATE__, __TIME__);
	new_render(&render, argc, argv);
	config_hooks(&render);
	log_scene(render.scene);
	mlx_loop(ft_getmlx());
	delete_render(&render);
	exit(EXIT_SUCCESS);
}
