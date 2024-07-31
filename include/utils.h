/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/31 14:55:11 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/param.h>

# include "mlx.h"
# include "mlx_int.h"

# include "libft.h"
# include "ft_vector.h"

typedef struct s_xpm
{
	char	*data;
	void	*im;
	int		h;
	int		w;
	int		bpp;
	int		sl;
	int		endian;
}	t_xpm;

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

# define MAX_RGB 255

int			rgba_to_int_gamma(t_vec4 c, float gamma);
int			rgba_to_int(t_vec4 c);
t_vec4		int_to_rgba(int color);
int			valid_color(t_vec4 c);

t_vec4		rgba_negative(t_vec4 rgba);
t_vec4		rgba_grayscale(t_vec4 rgba);
t_vec4		rgba_brightness(t_vec4 rgba, float brightness);
void		rgba_sum(t_vec4 *color, t_vec4 to_add, float brightness);

// mlx wrappers
typedef struct s_canvas	t_canvas;

void		*ft_getmlx(void);
void		*ft_new_image(int w, int h);
void		*ft_new_windows(int w, int h, char *name);
t_xpm		*ft_xpm_image(char *name);
t_vec4		get_pixel_xpm(t_xpm *xpm, t_vec2 *pix);

float		solve_quadratic(float a, float b, float c, float *roots);

// parser mandatory
t_vec3		mparser_vec3(char *vector);
t_vec4		mparser_vec4(char *vector);
t_vec4		mparser_color(char *vector);

// parser optional
int			oparser_vec3(char *vector, t_vec3 *v);
int			oparser_vec4(char *vector, t_vec4 *v);
int			oparser_color(char *vector, t_vec4 *v);

int			read_input(size_t size);
char		*read_param(size_t size);

#endif // UTILS_H