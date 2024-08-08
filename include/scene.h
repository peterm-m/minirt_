/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:11:53 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/08 19:57:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft_vector.h"
# include "object.h"

typedef struct s_ambient
{
	float	ratio;
	t_vec4	rgba;
	t_vec4	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec3		pos;
	t_vec3		normal;
	float		fov;
	t_matrix4	cam_world;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	float	ratio;
	t_vec4	rgba;
	t_vec4	color;
}	t_light;

typedef struct s_scene
{
	t_ambient	*a;
	t_camera	*c;
	t_camera	**cs;
	t_light		**l;
	t_object	**o;
}	t_scene;

void		fill_material(t_vec4 *rgba, t_material *mat);
t_vec3		mparser_vec3(char *vector);
int			oparser_vec3(char *vector, t_vec3 *v);

void		parser_ambient(char **tokens, t_scene *scene);
void		parser_camera(char **tokens, t_scene *scene);
void		parser_light(char **tokens, t_scene *scene);

int			o_parser_light(char **tokens, t_light *l);
int			o_parser_ambient(char **tokens, t_ambient *a);
int			o_parser_camera(char **tokens, t_camera *c);
int			oparser_qd(char **tokens, t_object *o);

void		log_ambient(t_ambient *a);
void		log_camera(t_camera *c);
void		log_light(t_light *l);
void		log_scene(t_scene *s);

void		transform_light(t_matrix4 *m, t_light *l);
void		transform_camera(t_matrix4 *m, t_camera *c);
void		transform_scene(t_matrix4 *m, t_scene *s);

t_scene		*new_scene(int argc, char **argv);
void		delete_scene(t_scene *scene);

#endif // SCENE_H
