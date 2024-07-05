
#include "minirt.h"
#include <sys/param.h>

/*
* TODO: podemos añadir a la estructura plano el producto 
*		np = ft_dotv3(pl->normal, pl->p);
* para no tener que calcularlo.
*/

float	interseccion_pl(t_ray *r, t_pl *pl)
{
	float	to_hit;
	float	nd;
	float	no;
	float	np;

	to_hit = INFINITY;
	nd = ft_dotv3(r->d, pl->normal);
	if (!islessgreater(nd, 0.0f))
		return (to_hit);
	no = ft_dotv3(r->o, pl->normal);
	np = ft_dotv3(pl->normal, pl->p);
	to_hit = MAX(np - no / nd, 0.0f);
	if (islessequal(to_hit, 0.0f))
		to_hit = INFINITY;
	return (to_hit);
}

/*
* TODO: podemos guardar r^2 para evitar calcularlo en sp
*/

float	intersection_sp(t_ray *r, t_sp *sp)
{
	t_vec3	m;
	float	b;
	float	c;
	float	discriminant;
	float	to_hit;

	to_hit = INFINITY;
	m = ft_subv3(r->o, sp->center);
	b = ft_dotv3(m, r->d);
	c = ft_lensqrv3(m) - sp->r * sp->r;
	if (isgreater(c, 0.0f) && isgreater(b, 0.0f))
		return (to_hit);
	discriminant = b * b - c;
	if (isgreater(discriminant, 0.0f))
		return (to_hit);
	to_hit = -b - sqrt(discriminant);
	if (islessequal(to_hit, 0.0f))
		to_hit = INFINITY;
	return (to_hit);
}

//float	interseccion_cy(t_ray *r, t_cy *cy);