/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:46 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/30 16:18:54 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int change_lights(t_render *r, t_hit h)
{
    int i;
    int index;
    char *light;

    (void)h;
    i = -1;
    while(r->scene->l[++i])
    {
        printf(BHMAG"Light index: [%d] - Color: (%f,%f,%f)\n", i,
        r->scene->l[i]->rgba.x, r->scene->l[i]->rgba.y, r->scene->l[i]->rgba.z);
    }
    printf("Select index: i = %d\n", i);
    index = read_input(5);
    if (index < 0 || index > i)
        return (EXIT_FAILURE);
    printf(BHYEL"Enter the new Light:\n"END);
    light = read_param(50);
    int j = o_parser_light(ft_split(light, ' '), r->scene->l[i]);
    return(j);
}
int change_ambient(t_render *r, t_hit h)
{
    int inp;
    printf(BHMAG"\n*** You are in change ambient mode ***\nSelect which"
    " attribute you want to change:\n\n"BHRED"0. Exit\n"BHCYN"1. Lights\n"BHGRN
    "2. Camera\n"BHYEL"3. Ambient Light\n"BHBLU"4. Environ\n\n"END);
    inp = read_input(4);
    if (inp == 0)
		return (exit_menu());
	else if (inp == 1)//lights
		return (change_lights(r, h));
	else if (inp == 2)//camera
		return (2);
	else if (inp == 3)//ambient
		return (3);
	else if (inp == 4)//env
		return (4);
    return (EXIT_SUCCESS);
}