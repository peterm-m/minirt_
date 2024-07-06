
#include "transformation.h"

t_matrix4	translate(t_vec3 translation)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[3][0] = translation.x;
	m.elements[3][1] = translation.y;
	m.elements[3][2] = translation.z;
	return (m);
}

t_matrix4	inv_translate(t_vec3 translation)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[3][0] = -translation.x;
	m.elements[3][1] = -translation.y;
	m.elements[3][2] = -translation.z;
	return (m);
}
