
#include "utils.h"

int	in_range(float f, float upper_lim, float lower_lim)
{
	return (isfinite(f) && (isgreaterequal(f, lower_lim)
			&& islessequal(f, upper_lim)));
}
