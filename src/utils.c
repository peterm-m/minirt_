/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   utils.c                                                                  */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/11 18:49:22 by pedromar                                 */
/*   Updated: 2024/07/04 11:21:21 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	*mallox(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		ft_error("malloc error");
	return (new);
}

int	in_range(float f, float upper_lim, float lower_lim)
{
	return (isfinite(f) && (isgreaterequal(f, lower_lim) 
		&& islessequal(f, upper_lim)));
}
