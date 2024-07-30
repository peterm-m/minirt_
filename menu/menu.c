/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:50:41 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/07/30 15:46:13 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int exit_menu()
{
	printf(BHRED"*** Exit from change mode ***\n");
	return (2);
}

int menu_ambient(t_render *r, t_hit h)
{
	(void)r;
	(void)h;
	return (1);
/* 	int 	m_exit;
	while (1)
	{
		m_exit = change_ambient(h);
		if (m_exit == EXIT_SUCCESS)
		{
			bound_object(h.o);
			ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
			printf(BHGRN"Changes added successfully\n"END);
			return (EXIT_SUCCESS);
		}
		else if (m_exit == 2)
			return (2);
		else
			printf(BHRED"Changes could not be added, try again"END);
	}*/
}

void	menu(t_render *r, t_ivec2 pixel)
{
	t_hit	h;
	int 	m_exit;

	gen_camray(&pixel, r->scene->c, &h.primary); 
	if (!check_hit(r->scene, &h))
	{
		printf("No hit\n");
		return ;
	}
	while (1)
	{
		m_exit = change(r, h);
		if (m_exit == EXIT_SUCCESS)
		{
			bound_object(h.o);
			ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
			printf(BHGRN"Changes added successfully\n"END);
			return ;
		}
		else if (m_exit == 2)
			return ;
		else
			printf(BHRED"Changes could not be added, try again"END);
	}
}
