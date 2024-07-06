
#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_vector.h"
# include "libft.h"

# include "utils.h"
# include "scene.h"
# include "canvas.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

# define WIN1_SX 1024
# define WIN1_SY 1024
# define IM1_SX 1024
# define IM1_SY 1024

typedef struct s_hit
{
	float	to_hit;
	t_vec3	normal;
	t_sp	*sp;
//	t_vec2	texture;
}	t_hit;

typedef struct s_ray
{
	t_vec3	o;
	t_vec3	d;
}	t_ray;

typedef struct s_render
{
	t_canvas	*canvas;
	t_scene		*scene;
}	t_render;

float		intersection_sp(t_ray *r, t_sp *sp);
float		intersection_pl(t_ray *r, t_pl *pl);
float		intersection_cy(t_ray *r, t_cy *cy);

void		new_render(t_render	*render, int argc, char **argv);
void		delete_render(t_render *render);
int			render_loop(t_render *r);

void		config_hooks(t_render *render);

#endif // MINIRT_H
