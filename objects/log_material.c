/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:31:19 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 14:28:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	log_material(t_material *m)
{
	printf("1. Ka = (%f, %f, %f);\n" \
		"2. Kd = (%f, %f, %f);\n" \
		"3. Ks = (%f, %f, %f);\n" \
		"4. gloss = %f\n" \
		"5. have texture = %d\n" \
		"6. have bump map = %d \n" \
		"7. have pattern = %d \n",
		m->k_a.x, m->k_a.y, m->k_a.z,
		m->k_d.x, m->k_d.y, m->k_d.z,
		m->k_s.x, m->k_s.y, m->k_s.z,
		m->glossiness,
		m->mat_info & HAVE_TEXTURE,
		m->mat_info & HAVE_BUMP,
		m->mat_info & HAVE_PATTERN);
}
