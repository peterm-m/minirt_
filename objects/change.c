/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:25:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/28 18:21:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	change_cy(t_render *r, t_hit h);
static int	change_qd(t_render *r, t_hit h);
static int	change_pl(t_render *r, t_hit h);
static int	change_sp(t_render *r, t_hit h);

int	change(t_render *r, t_hit h)
{
	static int	(*changes[4])(t_render *r, t_hit h) = {\
		change_sp,
		change_pl,
		change_cy,
		change_qd};

	printf(BHMAG"\n*** You are in change scene mode ***\nSelected object: ");
	return (changes[h.o->type](r, h));
}

static int	change_pl(t_render *r, t_hit h)
{
	char	*input_num;

	log_object(h.o);
    input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		return (obj_traslation(r, h));
	else if (ft_strncmp(input_num, "2", 1) == 0)
		return (obj_normal(r, h));
	else if (ft_strncmp(input_num, "3", 1) == 0)
		return (obj_repaint(r, h));
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
	return (EXIT_FAILURE);
}

static int	change_sp(t_render *r, t_hit h)
{
	char *input_num;

	log_object(h.o);
	input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		return (obj_traslation(r, h));
	else if (ft_strncmp(input_num, "2", 1) == 0)
		return (obj_resize(r, h));
	else if (ft_strncmp(input_num, "3", 1) == 0)
		return (obj_repaint(r, h));
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
	return (EXIT_FAILURE);
}

static int	change_cy(t_render *r, t_hit h)
{
	char *input_num;

	log_object(h.o);
    input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		return (obj_traslation(r, h));
	else if (ft_strncmp(input_num, "2", 1) == 0)
		return (obj_resize(r, h));
	else if (ft_strncmp(input_num, "3", 1) == 0)
		return (obj_repaint(r, h));
    else if (ft_strncmp(input_num, "4", 1) == 0)
		return (obj_resize_h(r, h));
    else if (ft_strncmp(input_num, "5", 1) == 0)
		return (obj_normal(r, h));
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
	return (EXIT_FAILURE);
}


static int	change_qd(t_render *r, t_hit h)
{
	char *input_num;

	log_object(h.o);
	input_num = read_input(20);
	if (ft_strncmp(input_num, "1", 1) == 0)
		return (obj_traslation(r, h));
	else if (ft_strncmp(input_num, "2", 1) == 0)
		return (obj_resize(r, h));
	else if (ft_strncmp(input_num, "3", 1) == 0)
		return (obj_repaint(r, h));
    else if (ft_strncmp(input_num, "4", 1) == 0)
		return (obj_resize_h(r, h));
    else if (ft_strncmp(input_num, "5", 1) == 0)
		return (obj_normal(r, h));
	else
		printf("¡Not a valid option: %s enter a valid one!\n", input_num);
	return (EXIT_FAILURE);
}
