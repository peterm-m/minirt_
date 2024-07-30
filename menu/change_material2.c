/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_material2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:21:14 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/30 18:26:51 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int change_texture(t_hit h)
{
    char    *file;
    
    printf(BHMAG"Enter the bump filename:\n"END);
    file = read_param(100);
    h.o->material.map_bump = ft_xpm_image(file);
    return (EXIT_SUCCESS);
}

int change_bump(t_hit h)
{
    char    *file;
    
    printf(BHMAG"Enter the bump filename:\n"END);
    file = read_param(100);
    h.o->material.map_bump = ft_xpm_image(file);
    return (EXIT_SUCCESS);
}