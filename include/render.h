
#ifndef RENDER_H
# define RENDER_H

# include "scene.h"
# include "canvas.h"

# define WIN1_SX 1024
# define WIN1_SY 1024
# define IM1_SX 1024
# define IM1_SY 1024

typedef struct s_render
{
	t_canvas	*canvas;
	t_scene		*scene;
}	t_render;

void		new_render(t_render	*render, int argc, char **argv);
void		delete_render(t_render *render);
void		config_hooks(t_render *render);

int			render_loop(t_render *r);

#endif // RENDER_H