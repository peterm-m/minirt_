/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_mandatory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:23:09 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 16:09:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
*                255,255,255
*       X      |      Y        |     Z
*    tokens[1] |   tokens[1]   |  tokens[2]
*/

t_vec3	mparser_vec3(char *vector)
{
	t_vec3	v;
	char	**tokens;

	tokens = ft_split(vector, ',');
	if (!tokens)
		ft_error("malloc error");
	if (ft_lenarr((void **)tokens) != 3)
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
*                255,255,255,255
*       X      |      Y        |     Z      |     ""      |
*    tokens[1] |   tokens[1]   |  tokens[2] |  tokens[2] |
*/

t_vec4	mparser_vec4(char *vector)
{
	t_vec4	v;
	char	**tokens;

	tokens = ft_split(vector, ',');
	if (!tokens)
		ft_error("malloc error");
	if (ft_lenarr((void **)tokens) != 4)
		ft_error("Invalid number of parameter in vec4");
	v = ft_vec4(0.0f, 0.0f, 0.0f, 0.0f);
	v.x = ft_atof(tokens[0]);
	v.y = ft_atof(tokens[1]);
	v.z = ft_atof(tokens[2]);
	v.w = ft_atof(tokens[3]);
	if (!(isfinite(v.x) && isfinite(v.y) && isfinite(v.z) && isfinite(v.w)))
		ft_error("Invalid number in vector");
	ft_iterarr((void **)tokens, free);
	free(tokens);
	return (v);
}

t_vec4	mparser_color(char *vector)
{
	t_vec4	v;

	v.rgb = mparser_vec3(vector);
	v.a = 0.0f;
	if (!valid_color(v))
		ft_error("Invalid color");
	return (v);
}
