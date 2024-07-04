
#include "minirt.h"

void	new_render(t_render	*render, int argc, char **argv)
{
	render->scene = new_scene(argc, argv);
	render->canvas = new_canvas();
}

void	delete_render(t_render *render)
{
	delete_canvas(render->canvas);
	delete_scene(render->scene);
}
