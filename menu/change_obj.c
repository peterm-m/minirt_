/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:25:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/30 17:35:54 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	change_cy(t_render *r, t_hit h, int num);
static int	change_qd(t_render *r, t_hit h, int num);
static int	change_pl(t_render *r, t_hit h, int num);
static int	change_sp(t_render *r, t_hit h, int num);

int	change(t_render *r, t_hit h)
{
	int		input;
	static int menu_num[4] = {4, 4, 6, 7};
	static int	(*changes[4])(t_render *r, t_hit h, int num) = {\
		change_sp,
		change_pl,
		change_cy,
		change_qd};

	printf(BHMAG"\n*** You are in change scene mode ***\nSelected object: ");
	cli_object(h.o);
    input = read_input(4);
	if (input < 0 || input > menu_num[h.o->type])
		return (printf(BHRED"¡Not a valid option, enter a valid one!\n"), EXIT_FAILURE);
	return (changes[h.o->type](r, h, input));
}

static int	change_pl(t_render *r, t_hit h, int num)
{
	if (num == 0)
		return (exit_menu());
	else if (num == 1)
		return (obj_traslation(h));
	else if (num == 2)
		return (obj_normal(h));
	else if (num == 3)
		return (change_material(r, h));
	else if (num == 4)
		return (change_ambient(r));
	return (EXIT_FAILURE);
}

static int	change_sp(t_render *r, t_hit h, int num)
{
	if (num == 0)
		return (exit_menu());
	else if (num == 1)
		return (obj_traslation(h));
	else if (num == 2)
		return (obj_resize(h));
	else if (num == 3)
		return (change_material(r, h));
	else if (num == 4)
		return (change_ambient(r));
	return (EXIT_FAILURE);
}

static int	change_cy(t_render *r, t_hit h, int num)
{
	if (num == 0)
		return (exit_menu());
	else if (num == 1)
		return (obj_traslation(h));
	else if (num == 2)
		return (obj_resize(h));
	else if (num == 3)
		return (change_material(r, h));
	else if (num == 4)
		return (change_ambient(r));
    else if (num == 5)
		return (obj_resize_h(h));
    else if (num == 6)
		return (obj_normal(h));

	return (EXIT_FAILURE);
}


static int	change_qd(t_render *r, t_hit h, int num)
{
	if (num == 0)
		return (exit_menu());
	else if (num == 1)
		return (obj_traslation(h));
	else if (num == 2)
		return (obj_resize(h));
	else if (num == 3)
		return (change_material(r, h));
	else if (num == 4)
		return (change_ambient(r));
    else if (num == 5)
		return (obj_resize_h(h));
    else if (num == 6)
		return (obj_normal(h));
	return (EXIT_FAILURE);
}
