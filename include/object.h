/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:04:39 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 17:34:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ft_vector.h"

typedef struct s_bound
{
	t_vec3	p_max;
	t_vec3	p_min;
}	t_bound;

typedef struct s_tr
{
	t_vec3	v0;
	t_vec3	v1;
	t_vec3	v2;
}	t_tr;


typedef struct s_disk
{
	t_vec3	center;
	t_vec3	normal;
	float	r2;
}	t_disk;

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
	float	ra;
	float	rb;
	float	h;
}	t_cn;

typedef enum e_type_obj
{
	obj_sphere,
	obj_plane,
	obj_cylinder,
	obj_cone,
	obj_disk,
	obj_triangle,
}	t_type_obj;

typedef union u_obj
{
	t_sp	sp;
	t_pl	pl;
	t_cy	cy;
	t_cn	cn;
	t_disk	disk;
	t_tr	tr;
}	t_obj;

typedef struct s_material
{
	t_vec4	color;
	t_vec3	k_diffuse;
	t_vec3	k_specular;
	float	shininess;
	char	*map_texture;
}	t_material;

typedef struct s_object
{
	t_type_obj	type;
	t_bound		bound;
	t_obj		obj;
	t_material	material;
	t_vec4		color;
}	t_object;

typedef struct s_ray	t_ray;
typedef struct s_scene	t_scene;
typedef struct s_hit	t_hit;

void	parser_object(char **tokens, t_scene *scene, t_type_obj type);
void	bound_object(t_object *obj);

float	intersection(t_ray *r, t_object *o);
void	normal(t_hit *h);
void	texture(t_hit *h);

void	log_object(t_object *o);

void	surface_info(t_hit *h);

void	transform_object(t_matrix4 *m, t_object *o);

int		bound_check(t_ray *r, t_object *o);

#endif // OBJECT_H