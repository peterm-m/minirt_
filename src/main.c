/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/13 17:47:54 by pedromar                                 */
/*   Updated: 2024/07/03 13:59:55 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_canvas	*canvas;

	(void)argc;
	(void)argv;
	printf("miniRT %s %s\n", __DATE__, __TIME__);
	canvas = new_canvas();
	set_control(canvas);
	mlx_loop(ft_getmlx());
	return (EXIT_SUCCESS);
}
