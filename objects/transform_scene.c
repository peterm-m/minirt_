/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:15:41 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/29 18:42:56 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	obj_repaint(t_hit h)
{
	char	*input_change;
	char	**rgba;
	t_vec4	colors;

	printf("Enter the new Color in the next format: 'r g b'\n");
	input_change = read_param(100);
	rgba = ft_split(input_change, ' ');
	if (ft_lenarr((void **)rgba) != 3 || !in_range(ft_atof(rgba[0]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[1]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[2]), 255.0, 0.0))
		return (EXIT_FAILURE);
	colors = ft_vec4(ft_atof(rgba[0]) / 255.0, ft_atof(rgba[1]) / 255.0,
			ft_atof(rgba[2]) / 255.0, 1.0);
	h.o->color = colors;
	return (EXIT_SUCCESS);
}

int	obj_resize(t_hit h)
{
	char	*input_change;
	float	new_radius;

	printf("Enter the new Radius in the next format: 'r'\n");
	input_change = read_param(100);
	if (!in_range(ft_atof(input_change), __FLT_MAX__, 0.0))
		return (EXIT_FAILURE);
	new_radius = ft_atof(input_change) * ft_atof(input_change);
    if (h.o->type == obj_sphere)
		h.o->obj.sp.r2 = new_radius;
	else if (h.o->type == obj_cylinder)
		h.o->obj.cy.r2 = new_radius;
//	else if (h.o->type == obj_quadric)   TODO: change
//		h.o->obj.qd.ra = new_radius;  TODO: change
	else
		printf(BHRED"Unsuported operation\n"END);
	return (EXIT_SUCCESS);
}

int	obj_resize_h(t_hit h)
{
	char	*input_change;
	float	new_height;

	printf("Enter the new Height in the next format: 'h'\n");
	input_change = read_param(100);
	if (!in_range(ft_atof(input_change), __FLT_MAX__, 0.0))
		return (EXIT_FAILURE);
	new_height = ft_atof(input_change);
	if (h.o->type == obj_cylinder)
		h.o->obj.cy.h = new_height;
//	else if (h.o->type == obj_quadric) TODO: change
//		h.o->obj.qd.h = new_height;    TODO: change
	else
		printf(BHRED"Unsuported operation\n"END);
	return (EXIT_SUCCESS);
}

int	obj_traslation(t_hit h)
{
	char	*input_change;
	char	**xyz;
	t_vec3	coords;

	printf("Enter the new Position in the next format: 'x y z'\n");
	input_change = read_param(100);
	xyz = ft_split(input_change, ' ');
	if (ft_lenarr((void **)xyz) != 3 || !in_range(ft_atof(xyz[0]), 1024, -1024)
		|| !in_range(ft_atof(xyz[1]), 1024, -1024)
		|| !in_range(ft_atof(xyz[2]), 1024, -1024))
		return (EXIT_FAILURE);
	coords = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	if (h.o->type == obj_sphere)
		h.o->obj.sp.center = coords;
	else if (h.o->type == obj_plane)
		h.o->obj.pl.p = coords;
	else if (h.o->type == obj_cylinder)
		h.o->obj.cy.center = coords;
//	else if (h.o->type == obj_quadric)  TODO: change
//		h.o->obj.qd.center = coords; TODO: change
	else
		printf(BHRED"Unsuported operation\n"END);
	return (EXIT_SUCCESS);
}

int	obj_normal(t_hit h)
{
	char	*input_change;
	char	**xyz;
	t_vec3	normal;

	printf("Enter the new Normal in the next format: 'x y z'\n");
	input_change = read_param(100);
	xyz = ft_split(input_change, ' ');
	if (ft_lenarr((void **)xyz) != 3 || !in_range(ft_atof(xyz[0]), 1.0, -1.0)
		|| !in_range(ft_atof(xyz[1]), 1.0, -1.0)
		|| !in_range(ft_atof(xyz[2]), 1.0, -1.0))
		return (EXIT_FAILURE);
	normal = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	normal = ft_normv3(normal);
	if (h.o->type == obj_plane)
		h.o->obj.pl.normal = normal;
	else if (h.o->type == obj_cylinder)
		h.o->obj.cy.normal = normal;
//	else if (h.o->type == obj_quadric) TODO: chenge
//		h.o->obj.qd.normal = normal;   TODO: chenge
	else
		printf(BHRED"Unsuported operation\n"END);
	return (EXIT_SUCCESS);
}
