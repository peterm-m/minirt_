/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:04:39 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 19:02:37 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <sys/param.h>
# include "ft_vector.h"

# define WAS_HERE static int ñ=1;if(ñ){printf("%d:%s\n", __LINE__, __FILE__);ñ=!ñ;}

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
t_vec3	n;
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

typedef struct s_qd
{
	t_matrix4	a;
	int			type;
	t_vec3		center;
	t_vec3		angles;
	t_vec3		coef;
	t_bound		bound_body;
}	t_qd;

typedef enum e_type_obj
{
	obj_sphere,
	obj_plane,
	obj_cylinder,
	obj_quadric,
	obj_disk,
	obj_triangle,
}	t_type_obj;

typedef union u_obj
{
	t_sp	sp;
	t_pl	pl;
	t_cy	cy;
	t_disk	disk;
	t_tr	tr;
	t_qd	qd;
}	t_obj;

typedef struct	s_xpm	t_xpm;

# define HAVE_TEXTURE 1
# define HAVE_PATTERN 2
# define HAVE_BUMP	  4

typedef struct s_material
{
	int		mat_info;
	t_vec4	k_a;
	t_vec4	k_d;
	t_vec4	k_s;
	float	glossiness;
	t_xpm	*texture;
	t_xpm	*bump_map;
}	t_material;

typedef struct s_object
{
	t_type_obj	type;
	t_bound		bound;
	t_obj		obj;
	t_material	material;
}	t_object;

typedef struct s_ray	t_ray;
typedef struct s_scene	t_scene;
typedef struct s_hit	t_hit;
typedef struct s_render	t_render;

// parser
char	*parser_sp(char **tokens, t_obj *o);
char	*parser_pl(char **tokens, t_obj *o);
char	*parser_cy(char **tokens, t_obj *o);
char	*parser_qd(char **tokens, t_obj *o);
char	*parser_disk(char **tokens, t_obj *o);
char	*parser_tr(char **tokens, t_obj *o);

void	parser_object(char **tokens, t_scene *scene, t_type_obj type);

// bounds
void	bound_cy(t_object *o);
void	bound_qd(t_object *o);
void	bound_pl(t_object *o);
void	bound_sp(t_object *o);
void	bound_disk(t_object *o);
void	bound_tr(t_object *o);

void	bound_object(t_object *obj);
float	bound_check(t_ray *r, t_bound *b);

// intersection
float	intersection_cy(t_ray *r, t_obj *o);
float	intersection_qd(t_ray *r, t_obj *o);
float	intersection_pl(t_ray *r, t_obj *o);
float	intersection_sp(t_ray *r, t_obj *o);
float	intersection_disk(t_ray *r, t_obj *o);
float	intersection_tr(t_ray *r, t_obj *o);
float	intersection_box(t_ray *r, t_obj *o);

float	intersection(t_ray *r, t_object *o);

// normal
void	normal_sp(t_hit *h);
void	normal_pl(t_hit *h);
void	normal_cy(t_hit *h);
void	normal_qd(t_hit *h);
void	normal_disk(t_hit *h);
void	normal_tr(t_hit *h);

void	normal(t_hit *h);

// texture
void	texture_sp(t_hit *h);
void	texture_pl(t_hit *h);
void	texture_cy(t_hit *h);
void	texture_qd(t_hit *h);
void	texture_disk(t_hit *h);
void	texture_tr(t_hit *h);

void	texture(t_hit *h);

// logs
void	log_sp(t_object *o);
void	log_pl(t_object *o);
void	log_cy(t_object *o);
void	log_qd(t_object *o);
void	log_disk(t_object *o);
void	log_tr(t_object *o);

void	log_object(t_object *o);

// transform

void	transform_sp(t_matrix4 *m, t_object *o);
void	transform_pl(t_matrix4 *m, t_object *o);
void	transform_cy(t_matrix4 *m, t_object *o);
void	transform_qd(t_matrix4 *m, t_object *o);
void	transform_disk(t_matrix4 *m, t_object *o);
void	transform_tr(t_matrix4 *m, t_object *o);

void	transform_object(t_matrix4 *m, t_object *o);

int		obj_resize(t_hit h);
int		obj_traslation(t_hit h);
int		obj_repaint(t_hit h);
int		obj_normal(t_hit h);
int		obj_resize_h(t_hit h);

void	surface_info(t_hit *h);

#endif // OBJECT_H