/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   arrays.c                                                                 */
/*                                                                            */
/*   By: pedromar <pedromar@student.42madrid.com                              */
/*                                                                            */
/*   Created: 2024/07/03 19:22:39 by pedromar                                 */
/*   Updated: 2024/07/03 21:29:18 by pedromar                                 */
/*                                                                            */
/* ************************************************************************** */

int	ft_lenarr(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

void	ft_iterarr(void **arr, void (*f)(void *))
{
	int	i;

	i = -1;
	while (arr[++i])
		f(arr[i]);
}
