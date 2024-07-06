
#include "ft_vector.h"

void	applay_transformation(t_matrix4 *m, t_vec3 *v, t_vec3 *d)
{
	t_vec4	aux;

	aux = ft_mulm4v(*m, ft_vec4(v->x, v->y, v->z, 1.0f));
	d->x = aux.x / aux.w;
	d->y = aux.y / aux.w;
	d->z = aux.z / aux.w;
}
