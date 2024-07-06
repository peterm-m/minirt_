
#ifndef SCENE_H
# define SCENE_H

# include "ft_vector.h"

typedef struct s_ambient
{
	float	ratio;
	t_vec4	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	normal;
	float	fov;
	t_matrix4	cam_world;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	float	ratio;
	t_vec4	color;
}	t_light;

typedef struct s_sp
{
	t_vec4	color;
	t_vec3	center;
	float	r;
}	t_sp;

typedef struct s_pl
{
	t_vec4	color;
	t_vec3	p;
	t_vec3	normal;
}	t_pl;

typedef struct s_cy
{
	t_vec4	color;
	t_vec3	center;
	t_vec3	normal;
	float	r;
	float	h;
}	t_cy;

typedef struct s_cn
{
	t_vec4	color;
	t_vec3	center;
	t_vec3	normal;
	float	r;
	float	h;
}	t_cn;

typedef struct s_scene
{
	t_ambient	*a;
	t_camera	*c;
	t_light		**l;
	t_sp		**sp;
	t_pl		**pl;
	t_cy		**cy;
	t_cn		**cn;
}	t_scene;

t_vec3		parser_vec3(char *vector);

void		parser_ambient(char **tokens, t_scene *scene);
void		parser_camera(char **tokens, t_scene *scene);
void		parser_light(char **tokens, t_scene *scene);

void		parser_sp(char **tokens, t_scene *scene);
void		parser_pl(char **tokens, t_scene *scene);
void		parser_cy(char **tokens, t_scene *scene);
void		parser_cn(char **tokens, t_scene *scene);

t_scene		*new_scene(int argc, char **argv);
void		delete_scene(t_scene *scene);

#endif // SCENE_H