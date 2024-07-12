/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:20:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/10 21:42:47 by pedromar         ###   ########.fr       */
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

# include "object.h"
# include "render.h"
# include "utils.h"
# include "scene.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

typedef struct s_ray
{
	t_vec3	o;
	t_vec3	d;
	float	t;
}	t_ray;

t_vec3	get_position(t_ray *ray);
void	primary_ray(t_ivec2 *pixel, t_camera *c, t_ray *ray);
void	secundary_ray(t_vec3 *from, t_vec3 *to, t_ray *ray);
void	log_render(t_render *r, t_ivec2 pixel);
void	log_ray(t_ray *r);

typedef struct s_hit
{
	t_object	*o;
	t_ray		primary;
	t_ray		secundary;
	t_vec3		pos;
	t_vec3		normal;
	t_vec2		texture;
}	t_hit;

int		shading(t_scene *scene, t_hit *h);
void	first_hit(t_scene *scene, t_hit *hit);
void	*in_shadow(t_scene *scene, t_hit *h);

#endif // MINIRT_H
