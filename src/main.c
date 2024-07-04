/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/13 17:47:54 by pedromar                                 */
/*   Updated: 2024/07/04 12:48:48 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>

int	main(int argc, char *argv[])
{
	t_render	render;

	printf("miniRT %s %s\n", __DATE__, __TIME__);
	render.scene = parser_scene(argc, argv);
	render.canvas = new_canvas();
	set_hooks(&render);
	mlx_loop(ft_getmlx());
	delete_render(&render);
	exit(EXIT_SUCCESS);
}
