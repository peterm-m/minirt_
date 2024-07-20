/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:44:15 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/20 12:02:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	solve_quadratic(float a, float b, float c, float *roots)
{
	float	discriminat;
	float	q;

	discriminat = b * b -4.0f * a * c;
	if (isless(discriminat, 0.0f))
	{
		roots[0] = INFINITY;
		roots[1] = INFINITY;
	}
	else if (isgreater(discriminat, 0.0f))
	{
		q = -0.5 * (b + (1.0 -2.0 * isgreater(b, 0.0)) * sqrt(discriminat));
		roots[0] = q / a;
		roots[1] = c / q;
	}
	else
		roots[0] = -0.5f * b / a;
	if (isgreater(roots[0], roots[1]))
	{
		q = roots[0];
		roots[0] = roots[1];
		roots[1] = q;
	}
	return (roots[0]);
}
