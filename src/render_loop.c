/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   render_loop.c                                                            */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 21:30:08 by pedromar                                 */
/*   Updated: 2024/07/04 12:29:53 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	render_loop(t_render *r)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN1_SX)
	{
		y = -1;
		while (++y < WIN1_SY)
		{
			ft_put_pixel(r->canvas, x, y, 0x00FF0000);
		}
	}
	ft_put_image_to_window(r->canvas);
	return (EXIT_SUCCESS);
}
