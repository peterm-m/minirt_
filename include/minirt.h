/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   minirt.h                                                                 */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/11 17:45:23 by pedromar                                 */
/*   Updated: 2024/07/03 14:01:04 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>//

# include "ft_vector.h"
# include "wrappers.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

# define M_PROJECT_LIMITS 1
# define OBJS_LIMIT 15
# define LIGHTS_LIMIT 5

# define WIN1_SX 1024
# define WIN1_SY 1024
# define IM1_SX 42
# define IM1_SY 42

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

void		*mallox(size_t size);
int			render_loop(void *r);
int			key_manager(int key, t_canvas *canvas);
void		set_control(t_canvas *canvas);
t_canvas	*new_canvas(void);
void		delete_canvas(t_canvas *canvas);

#endif // MINIRT_H
