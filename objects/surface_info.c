
#include "minirt.h"

void	surface_info(t_ray *r, t_hit *h)
{
	h->pos = ft_addv3(ft_mulv3f(r->d, h->to_hit), r->o);
	h->normal = normal(&h->pos, h->o);
	h->texture = texture(&h->pos, h->o);
}
