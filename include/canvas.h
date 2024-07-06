
#ifndef CANVAS_H
# define CANVAS_H

#include "ft_vector.h"

typedef struct s_canvas
{
	void	*mlx;
	void	*win;
	void	*im;
	int		bpp;
	int		sl;
	int		endian;
	char	*data;
}	t_canvas;

t_canvas	*new_canvas(void);
void		delete_canvas(t_canvas *canvas);
void		put_pixel(t_canvas *can, t_ivec2 *pix, int c);
void		canvas_to_window(t_canvas *canvas);

#endif // CANVAS_H