/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:04:39 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 13:19:10 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <sys/param.h>
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

// parser
t_vec3	parser_sp(char **tokens, t_obj *o);
t_vec3	parser_pl(char **tokens, t_obj *o);
t_vec3	parser_cy(char **tokens, t_obj *o);
t_vec3	parser_cn(char **tokens, t_obj *o);
t_vec3	parser_disk(char **tokens, t_obj *o);
t_vec3	parser_tr(char **tokens, t_obj *o);

void	parser_object(char **tokens, t_scene *scene, t_type_obj type);

// bounds
void	bound_cy(t_object *o);
void	bound_cn(t_object *o);
void	bound_pl(t_object *o);
void	bound_sp(t_object *o);
void	bound_disk(t_object *o);
void	bound_tr(t_object *o);

void	bound_object(t_object *obj);
int		bound_check(t_ray *r, t_object *o);

// intersection
float	intersection_cy(t_ray *r, t_obj *o);
float	intersection_cn(t_ray *r, t_obj *o);
float	intersection_pl(t_ray *r, t_obj *o);
float	intersection_sp(t_ray *r, t_obj *o);
float	intersection_disk(t_ray *r, t_obj *o);
float	intersection_tr(t_ray *r, t_obj *o);

float	intersection(t_ray *r, t_object *o);

// normal
void	normal_sp(t_hit *h);
void	normal_pl(t_hit *h);
void	normal_cy(t_hit *h);
void	normal_cn(t_hit *h);
void	normal_disk(t_hit *h);
void	normal_tr(t_hit *h);

void	normal(t_hit *h);

// texture
void	texture_sp(t_hit *h);
void	texture_pl(t_hit *h);
void	texture_cy(t_hit *h);
void	texture_cn(t_hit *h);
void	texture_disk(t_hit *h);
void	texture_tr(t_hit *h);

void	texture(t_hit *h);

// logs
void	log_sp(t_object *o);
void	log_pl(t_object *o);
void	log_cy(t_object *o);
void	log_cn(t_object *o);
void	log_disk(t_object *o);
void	log_tr(t_object *o);

void	log_object(t_object *o);

// transform

void	transform_sp(t_hit *h);
void	transform_pl(t_hit *h);
void	transform_cy(t_hit *h);
void	transform_cn(t_hit *h);
void	transform_disk(t_hit *h);
void	transform_tr(t_hit *h);

void	transform_object(t_matrix4 *m, t_object *o);

// other
void	surface_info(t_hit *h);

#endif // OBJECT_H