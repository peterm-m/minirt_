
#ifndef WRAPPERS_H
# define WRAPPERS_H

# include "mlx.h"
# include "mlx_int.h"
# include "minirt.h"
# include <stdlib.h>

typedef struct s_canvas	t_canvas;

void	*ft_getmlx(void);
void	*ft_new_image(int w, int h);
void	*ft_new_windows(int w, int h, char *name);

#endif // WRAPPERS_H