/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:08:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 15:55:55 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*   disk  50.0,0.0,20.6  0.0,0.0,1.0   14.2    10,0,255
*   type |    center   |  normal    | diam   | color
*  tok[0]|    tok[1]   |  tok[2]    | tok[3] | tok[4]
*/

char	*parser_disk(char **tokens, t_obj *o)
{
	o->disk.center = mparser_vec3(tokens[1]);
	o->disk.normal = mparser_vec3(tokens[2]);
	if (!islessgreater(ft_lenv3(o->disk.normal), 0.0f))
		ft_error("Invalid normal in disk");
	if (islessgreater(ft_lenv3(o->disk.normal), 1.0f))
		printf("Warning: normal in disk was normalized\n");
	o->disk.normal = ft_normv3(o->disk.normal);
	o->disk.r2 = ft_atof(tokens[3]);
	if (!isfinite(o->disk.r2) || islessequal(o->disk.r2, 0.0f))
		ft_error("Invalid diameter in disk");
	o->disk.r2 /= 2.0f;
	return (tokens[4]);
}

/*
*    tr    50.0,0.0,20.6   0.0,0.0,1.0   0.0,0.0,1.0    10,0,255
*   type |     v0        |   v1       |     v2       | color
*  tok[0]|    tok[1]     |  tok[2]    |    tok[3]    | tok[4]
*/

char	*parser_tr(char **tokens, t_obj *o)
{
	o->tr.v0 = mparser_vec3(tokens[1]);
	o->tr.v1 = mparser_vec3(tokens[2]);
	o->tr.v2 = mparser_vec3(tokens[3]);
	return (tokens[4]);
}
