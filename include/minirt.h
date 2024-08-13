/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:19:37 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/05 16:19:43 by pedromar         ###   ########.fr       */
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
t_vec3	trasmision_dir(t_vec3 *n, t_ray *r, float n1, float n2);
float	refractance(t_vec3 *n, t_ray *r, float n1, float n2);

void	log_render(t_render *r, t_ivec2 pixel);

# define AMBIENT 0
# define DIFFUSE 1
# define SPECULAR 2

typedef struct s_hit
{
	t_object	*o;
	t_vec3		pos;
	t_vec3		normal;
	t_vec2		texture;
	t_ray		primary;
	t_ray		secundary;
	t_vec4		data_o[3];
}	t_hit;

void	phong_term(t_light *l, t_hit *h, t_vec4 *color);
int		shading(t_scene *scene, t_hit *h);
bool	check_hit(t_scene *scene, t_hit *hit);
bool	check_shadow(t_scene *scene, t_hit *hit, int light);

#endif // MINIRT_H
