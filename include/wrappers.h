/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   wrappers.h                                                               */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/20 15:18:49 by pedromar                                 */
/*   Updated: 2024/07/04 12:26:17 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include "mlx.h"
# include "mlx_int.h"
# include "minirt.h"
# include <stdlib.h>

typedef struct s_canvas t_canvas;

void	*ft_getmlx(void);
void	*ft_new_image(int w, int h);
void	*ft_new_windows(int w, int h, char *name);
void	ft_put_image_to_window(t_canvas *canvas);
void	ft_put_pixel(t_canvas *can, int x, int y, int c);

#endif // WRAPPERS_H