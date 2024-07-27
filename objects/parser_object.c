/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:08:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/27 20:25:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define N_TOKEN_SPHERE 4
#define N_TOKEN_PLANE 4
#define N_TOKEN_CYLINDER 6
#define N_TOKEN_CONE 7
#define N_TOKEN_DISK 0
#define N_TOKEN_TRIENAGLE 0

void	parser_object(char **tokens, t_scene *scene, t_type_obj type)
{
	t_object		*obj;
	static int		n_tokens[6] = {\
		N_TOKEN_SPHERE, N_TOKEN_PLANE,
		N_TOKEN_CYLINDER, N_TOKEN_CONE,
		N_TOKEN_DISK, N_TOKEN_TRIENAGLE};
	static char	*(*parser[6])(char **, t_obj *) = {\
		parser_sp, parser_pl,
		parser_cy, parser_cn,
		parser_disk, parser_tr};
	char	*token_color;

	if (ft_lenarr((void **)tokens) != n_tokens[type])
		ft_error("Invalid number of argument in object");
	obj = mallox(sizeof(t_object));
	obj->type = type;
	token_color = parser[type](tokens, &obj->obj);
	obj->color = parser_color(token_color);
	obj->color = ft_divv4f(obj->color, 255.0f);
	bound_object(obj);
	scene->o = (t_object **)ft_addarr((void **)scene->o, obj);
}

/*
*     sp       0.0,0.0,20.6      12.6     10,0,255
*    type    |    center    |  diameter |  color
*  tokens[0] |   tokens[1]  | tokens[2] | tokens[3]
*/

char	*parser_sp(char **tokens, t_obj *o)
{
	o->sp.center = parser_vec3(tokens[1]);
	o->sp.r2 = ft_atof(tokens[2]);
	if (!isfinite(o->sp.r2) || islessequal(o->sp.r2, 0.0f))
		ft_error("Invalid diameter in sphere");
	o->sp.r2 /= 2.0f;
	o->sp.r2 *= o->sp.r2;
	return (tokens[3]);
}

/*
*     pl       0.0,0.0,20.6    0.0,1.0,0.0  10,0,255
*    type    |    point     |    normal   |  color
*  tokens[0] |   tokens[1]  |   tokens[2] | tokens[3]
*/

char	*parser_pl(char **tokens, t_obj *o)
{
	o->pl.p = parser_vec3(tokens[1]);
	o->pl.normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(o->pl.normal), 0.0f))
		ft_error("Invalid normal in plane");
	if (islessgreater(ft_lenv3(o->pl.normal), 1.0f))
		printf("Warning: normal in plane was normalized\n");
	o->pl.normal = ft_normv3(o->pl.normal);
	o->pl.n_dot_p = ft_dotv3(o->pl.p, o->pl.normal);
	return (tokens[3]);
}

/*
 *    cy       50.0,0.0,20.6  0.0,0.0,1.0     14.2        21.42     10,0,255
*    type    |    center    |    normal   | diameter  |  height   |  color
*  tokens[0] |   tokens[1]  |   tokens[2] | tokens[3] | tokens[4] | tokens[5]
*/

char	*parser_cy(char **tokens, t_obj *o)
{
	o->cy.center = parser_vec3(tokens[1]);
	o->cy.normal = parser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(o->cy.normal), 0.0f))
		ft_error("Invalid normal in cylinder");
	if (islessgreater(ft_lenv3(o->cy.normal), 1.0f))
		printf("Warning: normal in cylinder was normalized\n");
	o->cy.normal = ft_normv3(o->cy.normal);
	o->cy.r2 = ft_atof(tokens[3]);
	if (!isfinite(o->cy.r2) || islessequal(o->cy.r2, 0.0f))
		ft_error("Invalid diameter in cylinder");
	o->cy.r2 /= 2.0f;
	o->cy.r2 *= o->cy.r2;
	o->cy.h = ft_atof(tokens[4]);
	if (!isfinite(o->cy.h) || islessequal(o->cy.h, 0.0f))
		ft_error("Invalid height in cylinder");
	return (tokens[5]);
}

/*
*
*  F(x,y,z) = Ax2 + By2 + Cz2 + Dxy+ Exz + Fyz + Gx + Hy + Iz + J = 0
*
*    qd     A,B,C   D,E,F    G,H,I      J     p_min p_max  10,0,255 
*   type |  coef  |  coef  |  coef  | coef  |      |      | color
*  tok[0]| tok[1] | tok[2] | tok[3] | tok[4]|      |      | tok[6]
*/

char	*parser_cn(char **tokens, t_obj *o)
{
	o->qd.a.elements[0][0] = 1.0f;
	o->qd.a.elements[0][1] = 0.0f;
	o->qd.a.elements[0][2] = 0.0f;
	o->qd.a.elements[0][3] = 0.0f;
	o->qd.a.elements[1][0] = 0.0f;
	o->qd.a.elements[1][1] = 1.0f;
	o->qd.a.elements[1][2] = 0.0f;
	o->qd.a.elements[1][3] = 0.0f;
	o->qd.a.elements[2][0] = 0.0f;
	o->qd.a.elements[2][1] = 0.0f;
	o->qd.a.elements[2][2] = 1.0f;
	o->qd.a.elements[2][3] = -4.0f;
	o->qd.a.elements[3][0] = 0.0f;
	o->qd.a.elements[3][1] = 0.0f;
	o->qd.a.elements[3][2] = -4.0f;
	o->qd.a.elements[3][3] = 15.0f;
	return (tokens[6]);
}
//	o->cn.center = parser_vec3(tokens[1]);
//	o->cn.normal = parser_vec3(tokens[2]);
//	if (!islessgreater(ft_lenv3(o->cn.normal), 0.0f))
//		ft_error("Invalid normal in cone");
//	if (islessgreater(ft_lenv3(o->cn.normal), 1.0f))
//		printf("Warning: normal in cone was normalized\n");
//	o->cn.normal = ft_normv3(o->cn.normal);
//	o->cn.ra = ft_atof(tokens[3]);
//	if (!isfinite(o->cn.ra) || islessequal(o->cn.ra, 0.0f))
//		ft_error("Invalid diameter in cone");
//	o->cn.ra /= 2.0f;
//	o->cn.rb = ft_atof(tokens[4]);
//	if (!isfinite(o->cn.rb) || islessequal(o->cn.rb, 0.0f))
//		ft_error("Invalid diameter in cone");
//	o->cn.rb /= 2.0f;
//	o->cn.h = ft_atof(tokens[5]);
//	if (!isfinite(o->cn.h) || islessequal(o->cn.h, 0.0f))
//		ft_error("Invalid height in cone");
//	return (tokens[6]);

