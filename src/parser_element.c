/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser_element.c                                                         */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 17:05:31 by pedromar                                 */
/*   Updated: 2024/07/03 21:16:37 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*                255,255,255
*       X      |      Y        |     Z
*    tokens[1] |   tokens[1]   |  tokens[2]
*/

#define N_TOKEN_VEC3 3

t_vec3	parser_vec3(char *vector)
{
	t_vec3	v;
	char	**tokens;

	tokens = ft_split(vector, ',');
	if (!tokens)
		ft_error("malloc error");
	if (ft_lenarr((void **)tokens) != N_TOKEN_VEC3)
		ft_error("Invalid number of parameter in vec3");
	v = ft_vec3(0.0f, 0.0f, 0.0f);
	v.x = ft_atof(tokens[0]);
	v.y = ft_atof(tokens[1]);
	v.z = ft_atof(tokens[2]);
	if (!(isfinite(v.x) && isfinite(v.y) && isfinite(v.z)))
		ft_error("Invalid number in vector");
	ft_iterarr((void **)tokens, free);
	free(tokens);
	return (v);
}

/*
*     A             0.2        255,255,255
*    type    |     ratio     |   color
*  tokens[0] |   tokens[1]   |  tokens[2]
*/
#define N_TOKEN_AMBIENT 3

void	parser_ambient(char **tokens, t_scene *scene)
{
	if (scene->a)
		ft_error("Multiple ambient lights");
	if (ft_lenarr((void **)tokens) != N_TOKEN_AMBIENT)
		ft_error("Invalid number of parameter in ambient light");
	scene->a = mallox(sizeof(t_ambient));
	scene->a->ratio = ft_atof(tokens[1]);
	if (!isfinite(scene->a->ratio)
		|| !(isgreaterequal(scene->a->ratio, 0.0f)
			&& islessequal(scene->a->ratio, 1.0f)))
		ft_error("ambient lights with ratio out of range");
	scene->a->color.rgb = parser_vec3(tokens[2]);
	scene->a->color.a = 0.0f;
	if (!valid_color(scene->a->color))
		ft_error("lights with invalid color");
}

/*
*     C         -50.0,0,20       0,0,1       70
*    type    |     pos       |  normal   |  fov
*  tokens[0] |   tokens[1]   | tokens[2] | tokens[3]
*/
#define N_TOKEN_CAMERA 4

void	parser_camera(char **tokens, t_scene *scene)
{
	if (scene->c)
		ft_error("Multiple cameras");
	if (ft_lenarr((void **)tokens) != N_TOKEN_CAMERA)
		ft_error("Invalid number of parameter in camera");
	scene->c = mallox(sizeof(t_camera));
	scene->c->pos = parser_vec3(tokens[1]);
	scene->c->normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(scene->c->normal), 0.0f))
		ft_error("Invalid normal in camera");
	if (islessgreater(ft_lenv3(scene->c->normal), 1.0f))
		printf("Warning: normal in camera was normalized\n");
	scene->c->normal = ft_normv3(scene->c->normal);
	scene->c->fov = ft_atof(tokens[3]);
	if (!isfinite(scene->c->fov) || !(isgreaterequal(scene->c->fov, 0.0f)
			&& islessequal(scene->c->fov, 180.0f)))
		ft_error("Invalid fov in camera");
}

/*
*     L        -40.0,50.0,0.0     0.6       0,0,255
*    type    |      pos       |  ratio    |  color
*  tokens[0] |    tokens[1]   | tokens[2] | tokens[3]
*/
#define N_TOKEN_LIGHT 4

void	parser_light(char **tokens, t_scene *scene)
{
	if (scene->l)
		ft_error("Multiple lights");
	if (ft_lenarr((void **)tokens) != N_TOKEN_LIGHT)
		ft_error("Invalid number of argument in light");
	scene->l = mallox(sizeof(t_light));
	scene->l->pos = parser_vec3(tokens[1]);
	scene->l->ratio = ft_atof(tokens[2]);
	if (!isfinite(scene->l->ratio) || \
		!(isgreaterequal(scene->l->ratio, 0.0f)
			&& islessequal(scene->l->ratio, 1.0f)))
		ft_error("lights with ratio out of range");
	scene->l->color.rgb = parser_vec3(tokens[3]);
	scene->l->color.a = 0.0f;
	if (!valid_color(scene->l->color))
		ft_error("lights with invalid color");
}

/*
*     sp       0.0,0.0,20.6      12.6     10,0,255
*    type    |    center    |  diameter |  color
*  tokens[0] |   tokens[1]  | tokens[2] | tokens[3]
*/

void	parser_sp(char **tokens, t_scene *scene)
{
	if (ft_lenarr((void **)tokens) != N_TOKEN_LIGHT)
		ft_error("Invalid number of argument in sphere");
	scene->sp = mallox(sizeof(t_sp));
	scene->sp->center = parser_vec3(tokens[1]);
	scene->sp->r = ft_atof(tokens[2]);
	if (!isfinite(scene->sp->r) || islessequal(scene->sp->r, 0.0f))
		ft_error("Invalid diameter in sphere");
	scene->sp->r /= 2.0f;
	scene->sp->color.rgb = parser_vec3(tokens[3]);
	scene->sp->color.a = 0.0f;
	if (!valid_color(scene->sp->color))
		ft_error("Invallid color in sphere");
}
