/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:06:19 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/12 18:25:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transform_light(t_matrix4 *m, t_light *l)
{
	applay_transformation(m, &l->pos, &l->pos);
}

void	transform_scene(t_matrix4 *m, t_scene *s)
{
	int	i;

	i = -1;

	while (++i)
		transform_object(m, s->o[i]);
	i = -1;
	//while (++i)
	//	transform_light(m, s->l[i]);
}
