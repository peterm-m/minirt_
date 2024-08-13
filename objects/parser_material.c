/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:53:47 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/06 19:00:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_material(t_vec4 *rgba, t_material *mat)
{
	mat->mat_info = 0;
	mat->k_a = ft_divv4f(*rgba, 255.0f);
	mat->k_d = ft_divv4f(*rgba, 255.0f);
	mat->k_s = ft_divv4f(*rgba, 255.0f);
	mat->glossiness = 100.0f;
	mat->texture = NULL;
	mat->bump_map = NULL;
	return ;
}
