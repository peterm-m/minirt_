/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   in_range.c                                                               */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 21:33:15 by pedromar                                 */
/*   Updated: 2024/07/03 21:39:30 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_range(float f, float upper_lim, float lower_lim)
{
	return (isfinite(f) && (isgreaterequal(f, lower_lim) 
		&& islessequal(f, upper_lim)));
}
