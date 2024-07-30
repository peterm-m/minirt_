/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:59:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 17:36:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_vector.h"
# include "transformation.h"
# include "libft.h"

# include "colors.h"
# include "object.h"
# include "render.h"
# include "utils.h"
# include "scene.h"
# include "menu.h"

# include <time.h> 

# define INIT_CLOCK static clock_t total = 0;\
					static int n_frames = 0;\
					clock_t start = clock();

# define END_CLOCK(n_average, exit_after) total += (clock() - start);\
										if (n_frames++ == n_average || n_average < 0)\
										{\
											printf("%s:%d Averag time: %ld s %ld ms\n",\
											__FILE__, __LINE__,\
											(total/n_frames * 1000 / CLOCKS_PER_SEC) / 1000,\
											(total/n_frames * 1000 / CLOCKS_PER_SEC)%1000);\
											if (exit_after)\
													exit (EXIT_SUCCESS);\
											n_frames = 0;\
											total = 0;\
										}\

# define WAS_HEAR static int i=1;if(i){printf("%d:%s\n", __LINE__, __FILE__);i=!i;}

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

# define BIAS_RAY 0.99999f

typedef struct s_ray
{
	t_vec3	o;
	t_vec3	d;
	float	t;
}	t_ray;

void	gen_camray(t_ivec2 *pixel, t_camera *c, t_ray *ray);
void	gen_ray(t_vec3 pos_hit, t_vec3 pos_light, t_ray *ray);
void	log_ray(t_ray *r);

t_vec3	reflect_dir(t_vec3 *n, t_ray *r);
t_vec3	refract_dir(t_vec3 *n, t_ray *r, float n1, float n2);
float	refractance(t_vec3 *n, t_ray *r, float n1, float n2);

void	log_render(t_render *r, t_ivec2 pixel);
void	log_ray(t_ray *r);

t_vec3	reflect_dir(t_vec3 *n, t_ray *r);
t_vec3	refract_dir(t_vec3 *n, t_ray *r, float n1, float n2);
float	refractance(t_vec3 *n, t_ray *r, float n1, float n2);

void	log_render(t_render *r, t_ivec2 pixel);

typedef struct s_hit
{
	t_object	*o;
	t_vec3		pos;
	t_vec3		normal;
	t_vec2		texture;
	t_ray		primary;
	t_ray		secundary;
}	t_hit;

void	phong_term(t_light *l, t_hit *h, t_vec4 *color);
int		shading(t_scene *scene, t_hit *h);
bool	check_hit(t_scene *scene, t_hit *hit);
bool	check_shadow(t_scene *scene, t_hit *hit, int light);

#endif // MINIRT_H
