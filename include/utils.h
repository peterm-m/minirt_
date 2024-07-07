
#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>

# include "mlx.h"
# include "mlx_int.h"

# include "libft.h"
# include "ft_vector.h"

// Utils
void		*mallox(size_t size);

// Error
void		ft_error(char *msg);

// Ranges
int			in_range(float f, float upper_lim, float lower_lim);

// Files
# define SIZE_DUMMY_BUF 4056

ssize_t		len_file(char *file_name);
char		*load_file(char *file_name);

// Arrays
void		ft_iterarr(void **arr, void (*f)(void *));
int			ft_lenarr(void **arr);
void		**ft_addarr(void **arr, void *data);
void		**ft_newarr(void);

// Colors
int			set_rgba(t_vec4 c);
t_vec4		get_rgba(int color);
int			valid_color(t_vec4 c);

// mlx wrappers
typedef struct s_canvas	t_canvas;

void		*ft_getmlx(void);
void		*ft_new_image(int w, int h);
void		*ft_new_windows(int w, int h, char *name);

#endif // UTILS_H