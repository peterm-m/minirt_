/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:02:19 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/29 18:35:44 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

# define ERROR 1
# define WARNING 0 // TODO

void	ft_error(char *msg)
{
	printf("Error\n%s\n", msg);
		exit(EXIT_FAILURE);
}
