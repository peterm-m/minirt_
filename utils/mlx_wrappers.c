/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:13:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 11:57:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_getmlx(void)
{
	static void	*mlx;

	if (mlx == NULL)
		mlx = mlx_init();
	if (!mlx)
		ft_error("mlx error");
	return (mlx);
}

void	*ft_new_image(int w, int h)
{
	void	*ptr;

	ptr = mlx_new_image(ft_getmlx(), w, h);
	if (!ptr)
		ft_error("mlx error");
	return (ptr);
}

void	*ft_new_windows(int w, int h, char *name)
{
	void	*win;

	win = mlx_new_window(ft_getmlx(), w, h, name);
	if (!win)
		ft_error("mlx error");
	return (win);
}
