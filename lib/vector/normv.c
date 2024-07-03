/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   normv.c                                                                  */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/05/25 12:12:25 by pedromar                                 */
/*   Updated: 2024/07/03 14:00:43 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2	ft_normv2(t_vec2 v)
{
	return (ft_divv2f(v, ft_lenv2(v)));
}

t_vec3	ft_normv3(t_vec3 v)
{
	return (ft_divv3f(v, ft_lenv3(v)));
}

t_vec4	ft_normv4(t_vec4 v)
{
	return (ft_divv4f(v, ft_lenv4(v)));
}
