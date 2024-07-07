
#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_vector.h"
# include "transformation.h"
# include "libft.h"

# include "object.h"
# include "render.h"
# include "utils.h"
# include "scene.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

typedef struct s_hit
{
	t_object	*o;
	float		to_hit;
	t_vec3		pos;
	t_vec3		normal;
	t_vec2		texture;
	t_vec4		color;
}	t_hit;

typedef struct s_ray
{
	t_vec3	o;
	t_vec3	d;
}	t_ray;

#endif // MINIRT_H
