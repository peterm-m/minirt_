
#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_vector.h"
# include "transformation.h"
# include "libft.h"

# include "render.h"
# include "utils.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

typedef struct s_hit
{
	float	to_hit;
	t_vec3	pos;
	t_vec3	normal;
	t_pl	*pl;
//	t_vec2	texture;
}	t_hit;

typedef struct s_ray
{
	t_vec3	o;
	t_vec3	d;
}	t_ray;

float	intersection_sp(t_ray *r, t_sp *sp);
float	intersection_pl(t_ray *r, t_pl *pl);
float	intersection_cy(t_ray *r, t_cy *cy); //
float	intersection_cn(t_ray *r, t_cn *cn); //

t_vec3	normal_sp(t_vec3 *p, t_sp *sp);
t_vec3	normal_pl(t_vec3 *p, t_pl *pl);
t_vec3	normal_cy(t_vec3 *p, t_cy *cy); //
t_vec3	normal_cn(t_vec3 *p, t_cn *cn); //

t_vec3	texture_sp(t_vec3 *p, t_sp *sp); //
t_vec3	texture_pl(t_vec3 *p, t_pl *pl); //
t_vec3	texture_cy(t_vec3 *p, t_cy *cy); //
t_vec3	texture_cn(t_vec3 *p, t_cn *cn); //

#endif // MINIRT_H
