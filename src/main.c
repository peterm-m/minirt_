
#include "minirt.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_render	render;

	printf("miniRT %s %s\n", __DATE__, __TIME__);
	new_render(&render, argc, argv);
	config_hooks(&render);
	mlx_loop(ft_getmlx());
	delete_render(&render);
	exit(EXIT_SUCCESS);
}
