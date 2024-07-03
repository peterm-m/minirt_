/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:45:38 by pedromar          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	printv2(t_vec2 v)
{
	printf("%f %f \n", v.x, v.y);
}

void	printv3(t_vec3 v)
{
	printf("%f %f %f \n", v.x, v.y, v.z);
}

void	printv4(t_vec4 v)
{
	printf("%f %f %f %f \n", v.x, v.y, v.z, v.w);
}
