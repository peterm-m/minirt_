/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:08:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/08 20:29:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define N_TOKEN_SPHERE 4
#define N_TOKEN_PLANE 4
#define N_TOKEN_CYLINDER 6
#define N_TOKEN_QUADRIC 8

void	parser_object(char **tokens, t_scene *scene, t_type_obj type)
{
	t_vec4			color;
	t_object		*obj;
	static int		n_tokens[6] = {\
		N_TOKEN_SPHERE, \
		N_TOKEN_PLANE, \
		N_TOKEN_CYLINDER, \
		N_TOKEN_QUADRIC};
	static char		*(*parser[6])(char **, t_obj *) = {\
		parser_sp, \
		parser_pl, \
		parser_cy, \
		parser_qd};
	char			*token_color;

	if (ft_lenarr((void **)tokens) != n_tokens[type])
		ft_error("Invalid number of argument in object");
	obj = mallox(sizeof(t_object));
	obj->type = type;
	token_color = parser[type](tokens, &obj->obj);
	color = mparser_color(token_color);
	fill_material(&color, &obj->material);
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
	o->sp.center = mparser_vec3(tokens[1]);
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
	o->pl.p = mparser_vec3(tokens[1]);
	o->pl.normal = mparser_vec3(tokens[2]);
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
	o->cy.center = mparser_vec3(tokens[1]);
	o->cy.normal = mparser_vec3(tokens[2]);
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
	o->cy.center = ft_subv3(o->cy.center, \
		ft_mulv3f(o->cy.normal, o->cy.h / 2.0f));
	return (tokens[5]);
}

/*
* Generic Quadric
* F(x,y,z) = Ax^2 + By^2 + Cz^2 + Dxy+ Exz + Fyz + Gx + Hy + Iz + J = 0
*
* Subtipes:
*      0. ±A x^2 ±B y^2 ±C z^2       + 1 = 0
*      1. ±A x^2 ±B y^2 ±C z^2           = 0
*      2. ±A x^2 ±B y^2 ±C z^2       - 1 = 0
*      3. ±A x^2        ±C z^2 ± B y     = 0
*
* Sphere                  : A>0, B=a, C=a, subtype = 2
* Ellipsoid               : A>0, B>0, C>0, subtype = 2
* Cone                    : A>0, B<0, C>0, subtype = 1
* Hyperboloid of 1 sheets : A>0, B<0, C>0, subtype = 2
* Hyperboloid of 2 sheets : A>0, B<0, C>0, subtype = 0
* Cylinder                : A>0, B=0, C>0, subtype = 2
* Slab                    : A>0, B=0, C=0, subtype = 2
* Hyperbolic Cylinder     : A>0, B=0, C<0, subtype = 0
* Paraboloid              : A>0, B<0, C>0  subtype = 3
* Hyperbolic paraboloid   : A>0, B<0, C<0  subtype = 3
*
*    qd      3     A,B,C  x0,y0,z0  u,v,w   l0,m0,n0 l1,m1,n1 255,255,255
*   type |subtype| coef  | trasla |rotation|  min   |  max   | color
*  tok[0]|tok[1] |tok[2] | tok[3] | tok[4] | tok[5] | tok[6] | tok[7]
*/

char	*parser_qd(char **tokens, t_obj *o)
{
	t_matrix4	w2obj;

	o->qd.type = ft_atoi(tokens[1]);
	if (!(o->qd.type > -1 && o->qd.type < 4))
		ft_error("Invalid subtype in quadric");
	o->qd.coef = mparser_vec3(tokens[2]);
	o->qd.center = mparser_vec3(tokens[3]);
	o->qd.angles = mparser_vec3(tokens[4]);
	o->qd.bound_body.p_min = mparser_vec3(tokens[5]);
	o->qd.bound_body.p_max = mparser_vec3(tokens[6]);
	o->qd.a = ft_mat4();
	o->qd.a.elements[0][0] = o->qd.coef.x;
	o->qd.a.elements[2][2] = o->qd.coef.z;
	o->qd.a.elements[1][1] = o->qd.coef.y * (o->qd.type != 3);
	o->qd.a.elements[1][3] = o->qd.coef.y / 2.0f * (o->qd.type == 3);
	o->qd.a.elements[3][1] = o->qd.a.elements[1][3];
	o->qd.a.elements[3][3] = (o->qd.type == 0) - (o->qd.type == 2);
	w2obj = get_invtransform(o->qd.center, o->qd.angles, ft_vec3(1, 1, 1));
	o->qd.a = ft_mulm4m(w2obj, ft_mulm4m(o->qd.a, ft_transposem4(w2obj)));
	return (tokens[7]);
}
