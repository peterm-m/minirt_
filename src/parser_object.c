
#include "minirt.h"

/*
*     sp       0.0,0.0,20.6      12.6     10,0,255
*    type    |    center    |  diameter |  color
*  tokens[0] |   tokens[1]  | tokens[2] | tokens[3]
*/
#define N_TOKEN_SPHERE 4

void	parser_sp(char **tokens, t_scene *scene)
{
	t_sp	*sp;

	if (ft_lenarr((void **)tokens) != N_TOKEN_SPHERE)
		ft_error("Invalid number of argument in sphere");
	sp = mallox(sizeof(t_sp));
	sp->center = parser_vec3(tokens[1]);
	sp->r = ft_atof(tokens[2]);
	if (!isfinite(sp->r) || islessequal(sp->r, 0.0f))
		ft_error("Invalid diameter in sphere");
	sp->r /= 2.0f;
	sp->color.rgb = parser_vec3(tokens[3]);
	sp->color.a = 0.0f;
	if (!valid_color(sp->color))
		ft_error("Invallid color in sphere");
	scene->sp = (t_sp **)ft_addarr((void **)scene->sp, sp);
}

/*
*     pl       0.0,0.0,20.6    0.0,1.0,0.0  10,0,255
*    type    |    point     |    normal   |  color
*  tokens[0] |   tokens[1]  |   tokens[2] | tokens[3]
*/
#define N_TOKEN_PLANE 4

void	parser_pl(char **tokens, t_scene *scene)
{
	t_pl	*pl;

	if (ft_lenarr((void **)tokens) != N_TOKEN_PLANE)
		ft_error("Invalid number of argument in plane");
	pl = mallox(sizeof(t_pl));
	pl->p = parser_vec3(tokens[1]);
	pl->normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(pl->normal), 0.0f))
		ft_error("Invalid normal in plane");
	if (islessgreater(ft_lenv3(pl->normal), 1.0f))
		printf("Warning: normal in plane was normalized\n");
	pl->normal = ft_normv3(pl->normal);
	pl->color.rgb = parser_vec3(tokens[3]);
	pl->color.a = 0.0f;
	if (!valid_color(pl->color))
		ft_error("Invallid color in plane");
	scene->pl = (t_pl **)ft_addarr((void **)scene->pl, pl);
}

/*
 *    cy       50.0,0.0,20.6  0.0,0.0,1.0     14.2        21.42     10,0,255
*    type    |    center    |    normal   | diameter  |  height   |  color
*  tokens[0] |   tokens[1]  |   tokens[2] | tokens[3] | tokens[4] | tokens[5]
*/
#define N_TOKEN_CYLINDER 6

void	parser_cy(char **tokens, t_scene *scene)
{
	t_cy	*cy;

	if (ft_lenarr((void **)tokens) != N_TOKEN_CYLINDER)
		ft_error("Invalid number of argument in cylinder");
	cy = mallox(sizeof(t_cy));
	cy->center = parser_vec3(tokens[1]);
	cy->normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(cy->normal), 0.0f))
		ft_error("Invalid normal in cylinder");
	if (islessgreater(ft_lenv3(cy->normal), 1.0f))
		printf("Warning: normal in cylinder was normalized\n");
	cy->r = ft_atof(tokens[3]);
	if (!isfinite(cy->r) || islessequal(cy->r, 0.0f))
		ft_error("Invalid diameter in cylinder");
	cy->r /= 2.0f;
	cy->h = ft_atof(tokens[4]);
	if (!isfinite(cy->h) || islessequal(cy->h, 0.0f))
		ft_error("Invalid height in cylinder");
	cy->normal = ft_normv3(cy->normal);
	cy->color.rgb = parser_vec3(tokens[5]);
	cy->color.a = 0.0f;
	if (!valid_color(cy->color))
		ft_error("Invallid color in cylinder");
	scene->cy = (t_cy **)ft_addarr((void **)scene->cy, cy);
}
