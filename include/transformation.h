/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:38:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:38:19 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

# include "ft_vector.h"

// Trasformations
t_matrix4	lookatr(t_vec3 target, t_vec3 updir, t_vec3 eye);
t_matrix4	lookatl(t_vec3 target, t_vec3 updir, t_vec3 eye);
t_matrix4	inv_lookat(t_matrix4 lookat_m);

t_matrix4	translate(t_vec3 translation);
t_matrix4	inv_translate(t_vec3 translation);

t_matrix4	scale(t_vec3 scale);
t_matrix4	inv_scale(t_vec3 scale);

t_matrix4	rotationr(float a, t_vec3 axis);
t_matrix4	rotationl(float a, t_vec3 axis);
t_matrix4	inv_rotation(float a, t_vec3 axis);

t_matrix4	get_transform(t_vec3 pos, t_vec3 rot, t_vec3 sca);
t_matrix4	get_invtransform(t_vec3 pos, t_vec3 rot, t_vec3 sca);

void		applay_transformation(t_matrix4 *m, t_vec3 *v, t_vec3 *d);

#endif // TRANSFORMATION_H
