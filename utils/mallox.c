
#include "utils.h"

void	*mallox(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		ft_error("malloc error");
	return (new);
}
