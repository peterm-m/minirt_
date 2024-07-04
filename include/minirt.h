/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   minirt.h                                                                 */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/11 17:45:23 by pedromar                                 */
/*   Updated: 2024/07/04 12:49:08 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_vector.h"
# include "libft.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

# define M_PROJECT_LIMITS 1
# define OBJS_LIMIT 15
# define LIGHTS_LIMIT 5

# define WIN1_SX 1024
# define WIN1_SY 1024
# define IM1_SX 1024
# define IM1_SY 1024

# include "wrappers.h"
# include "scene.h"

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

typedef struct s_render
{
	t_canvas	*canvas;
	t_scene		*scene;
}	t_render;

t_scene		*parser_scene(int argc, char **argv);
void		*mallox(size_t size);
void		ft_error(char *msg);
int			in_range(float f, float upper_lim, float lower_lim);
int			render_loop(t_render *r);
int			key_manager(int key, t_render *render);
void		set_hooks(t_render *render);
t_canvas	*new_canvas(void);
int			delete_render(t_render *render);

int			set_rgba(t_vec4 c);
t_vec4		get_rgba(float color);
int			valid_color(t_vec4 c);

void		ft_iterarr(void **arr, void (*f)(void *));
int			ft_lenarr(void **arr);

#endif // MINIRT_H
