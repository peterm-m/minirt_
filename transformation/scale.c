
#include "transformation.h"

t_matrix4	scale(t_vec3 scale)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[0][0] = scale.x;
	m.elements[1][1] = scale.y;
	m.elements[2][2] = scale.z;
	return (m);
}

t_matrix4	inv_scale(t_vec3 scale)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[0][0] = 1.0f / scale.x;
	m.elements[1][1] = 1.0f / scale.y;
	m.elements[2][2] = 1.0f / scale.z;
	return (m);
}
