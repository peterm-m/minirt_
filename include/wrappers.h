/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   wrappers.h                                                               */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/20 15:18:49 by pedromar                                 */
/*   Updated: 2024/07/03 13:51:38 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include "mlx.h"
# include "mlx_int.h"
# include <stdlib.h>

void	*ft_getmlx(void);
void	*ft_new_image(int w, int h);
void	*ft_new_windows(int w, int h, char *name);
void	*mallox(size_t size);

#endif // WRAPPERS_H