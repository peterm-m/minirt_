/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:13:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/19 21:12:18 by pedromar         ###   ########.fr       */
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

t_xpm	*ft_xpm_image(char *name)
{
	t_xpm	*xpm;

	xpm = mallox(sizeof(t_xpm));
	xpm->im = mlx_xpm_file_to_image(ft_getmlx(), name , &xpm->h, &xpm->w);
	if (!xpm->im)
		ft_error("mlx error");
	xpm->data =  mlx_get_data_addr(xpm->im, &xpm->bpp, &xpm->sl, &xpm->endian);
	return (xpm);
}

unsigned int	get_pixel_xpm(t_xpm *xpm, t_ivec2 pix)
{
	if (pix.y < xpm->h && pix.y < xpm->w)
		return (*(unsigned int *)\
			(xpm->data + (pix.y * xpm->sl + pix.x * (xpm->bpp / 8))));
	else
		return (0);
}
