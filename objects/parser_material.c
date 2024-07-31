/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:53:47 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 17:24:58 by pedromar         ###   ########.fr       */
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
