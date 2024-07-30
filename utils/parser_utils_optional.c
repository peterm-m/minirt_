/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_optional.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:23:09 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 16:15:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
*                255,255,255
*       X      |      Y        |     Z
*    tokens[1] |   tokens[1]   |  tokens[2]
*/

int	oparser_vec3(char *vector, t_vec3 *v)
{
	char	**tokens;

	tokens = ft_split(vector, ',');
	if (!tokens)
		ft_error("malloc error");
	if (ft_lenarr((void **)tokens) == 3)
	{
		v->x = ft_atof(tokens[0]);
		v->y = ft_atof(tokens[1]);
		v->z = ft_atof(tokens[2]);
		if (isfinite(v->x) && \
			isfinite(v->y) && \
			isfinite(v->z))
			return (EXIT_SUCCESS);
	}
	ft_iterarr((void **)tokens, free);
	free(tokens);
	printf("Invalid vector");
	return (EXIT_FAILURE);
}

/*
*                255,255,255,255
*       X      |      Y        |     Z      |     ""      |
*    tokens[1] |   tokens[1]   |  tokens[2] |  tokens[2] |
*/

int	oparser_vec4(char *vector, t_vec4 *v)
{
	char	**tokens;

	tokens = ft_split(vector, ',');
	if (!tokens)
		ft_error("malloc error");
	if (ft_lenarr((void **)tokens) == 4)
	{
		v->x = ft_atof(tokens[0]);
		v->y = ft_atof(tokens[1]);
		v->z = ft_atof(tokens[2]);
		v->w = ft_atof(tokens[3]);
		if (isfinite(v->x) && \
			isfinite(v->y) && \
			isfinite(v->z) && \
			isfinite(v->w))
			return (EXIT_SUCCESS);
	}
	ft_iterarr((void **)tokens, free);
	free(tokens);
	printf("Invalid vector");
	return (EXIT_FAILURE);
}

int	oparser_color(char *vector, t_vec4	*v)
{
	t_vec4	a;

	a.w = 0.0f;
	if (oparser_vec3(vector, &a.rgb) || !valid_color(a))
	{
		printf("Invalid color");
		return (EXIT_FAILURE);
	}
	v->r = a.r;
	v->g = a.g;
	v->b = a.b;
	v->w = a.w;
	return (EXIT_SUCCESS);
}
