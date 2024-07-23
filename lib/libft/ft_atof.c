/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:15 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/23 10:17:03 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: en caso de erorr retornar NaN

static float	convert_num(char *str, int decimal_found,
		float fraction, float result)
{
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (decimal_found)
			{
				fraction /= 10.0;
				result += (*str - '0') * fraction;
			}
			else
				result = result * 10.0 + (*str - '0');
		}
		else if (*str == '.')
		{
			if (decimal_found)
				break ;
			decimal_found = 1;
		}
		else
			break ;
		str++;
	}
	return (result);
}

float	ft_atof(char *str)
{
	float	result;
	float	fraction;
	int		sign;
	int		decimal_found;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	decimal_found = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = convert_num(str, decimal_found, fraction, result);
	return (sign * result);
}
