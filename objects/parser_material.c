/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:53:47 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 18:49:49 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_material(t_vec4 *rgba, t_material *mat)
{
	mat->mat_info = 0;
	mat->k_a = ft_divv4f(*rgba, 255.0f);
	mat->k_d = mat->k_a;
	mat->k_s = mat->k_a;
	mat->glossiness = 100.0f;
	mat->texture = NULL;
	mat->bump_map = NULL;
	return ;
}
