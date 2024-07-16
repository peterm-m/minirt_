/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:04:39 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/16 15:37:45 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ft_vector.h"

typedef struct s_sp
{
	t_vec3	center;
	float	r2;
}	t_sp;

typedef struct s_pl
{
	t_vec3	p;
	t_vec3	normal;
	float	n_dot_p;
}	t_pl;

typedef struct s_cy
{
	t_vec3	center;
	t_vec3	normal;
	float	r2;
	float	h;
}	t_cy;

typedef struct s_cn
{
	t_vec3	center;
	t_vec3	normal;
	float	r;
	float	h;
}	t_cn;

typedef enum e_type_obj
{
	obj_sphere,
	obj_plane,
	obj_cylinder,
	obj_cone
}	t_type_obj;

typedef union u_obj
{
	t_sp	sp;
	t_pl	pl;
	t_cy	cy;
	t_cn	cn;
}	t_obj;

typedef struct s_object
{
	t_type_obj	type;
	t_obj		obj;
	t_vec4		color;
}	t_object;

typedef struct s_ray	t_ray;
typedef struct s_scene	t_scene;
typedef struct s_hit	t_hit;

void	parser_object(char **tokens, t_scene *scene, t_type_obj type);

float	intersection(t_ray *r, t_object *o);
void	normal(t_hit *h);
void	texture(t_hit *h);

void	log_object(t_object *o);

void	surface_info(t_hit *h);

void	transform_object(t_matrix4 *m, t_object *o);

#endif // OBJECT_H