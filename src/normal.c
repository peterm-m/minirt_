
#include "minirt.h"

t_vec3	normal_sp(t_vec3 *p, t_sp *sp)
{
	t_vec3	v;

	v = ft_subv3(*p, sp->center);
	return (ft_divv3f(v, ft_lenv3(v)));
}

t_vec3	normal_pl(t_vec3 *p, t_pl *pl)
{
	(void) p;
	return (pl->normal);
}
