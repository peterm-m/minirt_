/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/13 17:47:54 by pedromar                                 */
/*   Updated: 2024/07/03 21:39:34 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>

int	main(int argc, char *argv[])
{
	t_render	render;

	printf("miniRT %s %s\n", __DATE__, __TIME__);
	render.scene = parser(argc, argv);
	render.canvas = new_canvas();
	set_control(&render);
	mlx_loop(ft_getmlx());
	exit(EXIT_SUCCESS);
}
