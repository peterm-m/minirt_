/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_material2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:21:14 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/30 19:18:03 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int change_texture(t_hit h)
{
    char    *file;
    t_xpm *x;
    
    printf(BHMAG"Enter the Texture filename:\n"END);
    file = read_param(100);
    x = ft_xpm_image(file);
    if (x == NULL)
        return (EXIT_FAILURE);
    if (h.o->material.mat_info & HAVE_TEXTURE)
        {
            mlx_destroy_image(ft_getmlx(),  h.o->material.texture->im);
            free(h.o->material.texture);
        }
    else
        h.o->material.mat_info |= HAVE_TEXTURE;
    h.o->material.texture = x;
    return (EXIT_SUCCESS);
}

int change_bump(t_hit h)
{
    char    *file;
    t_xpm *x;
    
    printf(BHMAG"Enter the Bump filename:\n"END);
    file = read_param(100);
    x = ft_xpm_image(file);
    if (x == NULL)
        return (EXIT_FAILURE);
    if (h.o->material.mat_info & HAVE_BUMP)
        {
            mlx_destroy_image(ft_getmlx(),  h.o->material.bump_map->im);
            free(h.o->material.bump_map);
        }
    else
        h.o->material.mat_info |= HAVE_BUMP;
    h.o->material.bump_map = x;
    return (EXIT_SUCCESS);
}

int change_pattern(t_hit h)
{
    if (h.o->material.mat_info & HAVE_PATTERN)
        h.o->material.mat_info -= HAVE_PATTERN;
    else
        h.o->material.mat_info |= HAVE_PATTERN;
    return (EXIT_SUCCESS);
}

int change_gls(t_hit h)
{
    char    *inp;
    float   g;

    printf("Actual Glosiness: %f\nEnter the new one in the "\
    "next range: 0 - 10.000\n", rint(h.o->material.glossiness));
    inp = read_param(50);
    if (!in_range(ft_atof(inp), 10000.0, 0.0))
        return (printf(BHRED"Invalid arguments\n"), EXIT_FAILURE);
    g = ft_atof(inp);
	h.o->material.glossiness = g;
    return (EXIT_SUCCESS);
}