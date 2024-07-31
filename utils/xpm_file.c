/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:45:20 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 13:36:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_xpm	*ft_xpm_image(char *file_name)
{
	int		len_file_name;
	t_xpm	*xpm;

	len_file_name = ft_strlen(file_name);
	if (len_file_name < 4 && \
		ft_strncmp(file_name + len_file_name - 4, ".xpm", 4))
		printf("Invalid name: mandatory extension xpm");
	xpm = mallox(sizeof(t_xpm));
	xpm->im = mlx_xpm_file_to_image(ft_getmlx(), file_name, \
		&xpm->h, &xpm->w);
	if (!xpm->im)
	{
		printf("xpm file error\n");
		return (NULL);
	}
	xpm->data = mlx_get_data_addr(xpm->im, &xpm->bpp, &xpm->sl, &xpm->endian);
	if (!xpm->data)
	{
		printf("xpm file error\n");
		mlx_destroy_image(ft_getmlx(), xpm->im);
		return (NULL);
	}
	return (xpm);
}

t_vec4	get_pixel_xpm(t_xpm *xpm, t_vec2 *pix)
{
	char	*dst;
	t_vec4	color;
	t_ivec2	ij;

	ij.x = (int)floorf(xpm->h * pix->x);
	ij.y = (int)floorf(xpm->w * pix->y);
	dst = (xpm->data + (ij.y * xpm->sl + ij.x * (xpm->bpp / 8)));
	color = int_to_rgba(*(unsigned int *)dst);
	return (color);
}
