/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   wrappers.c                                                               */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/11 18:49:22 by pedromar                                 */
/*   Updated: 2024/07/03 13:56:10 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_getmlx(void)
{
	static void	*mlx;

	if (mlx == NULL)
		mlx = mlx_init();
	if (!mlx)
	{
		printf("mlx error\n");
		exit(EXIT_FAILURE);
	}
	return (mlx);
}

void	*ft_new_image(int w, int h)
{
	void	*ptr;

	ptr = mlx_new_image(ft_getmlx(), w, h);
	if (!ptr)
	{
		printf("mlx error\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	*ft_new_windows(int w, int h, char *name)
{
	void	*win;

	win = mlx_new_window(ft_getmlx(), w, h, name);
	if (!win)
	{
		printf("mlx error\n");
		exit(EXIT_FAILURE);
	}
	return (win);
}

void	ft_put_image_to_window(t_canvas *canvas)
{
	mlx_put_image_to_window(ft_getmlx(), canvas->win, canvas->im, 0, 0);
}

void	*mallox(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
	{
		printf("malloc error\n");
		exit (EXIT_FAILURE);
	}
	return (new);
}
