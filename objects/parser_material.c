/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:53:47 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 17:36:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_material(t_vec4 *rgba, t_material *mat)
{
	mat->mat_info = 0;
	mat->k_a = ft_divv4f(*rgba, 255.0f);
	mat->k_d = mat->k_a;
	mat->k_s = mat->k_a;
	mat->glossiness = 1.0f;
	mat->optical_density = 0.0f;
	mat->dissolve = 0;
	mat->ilumination_model = 0;
	mat->texture = NULL;
	mat->map_bump = NULL;
	return ;
}
