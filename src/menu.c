#include "minirt.h"

void menu(t_render *r, t_ivec2 pixel)
{
	t_hit	h;

	gen_camray(&pixel, r->scene->c, &h.primary); 
	if (check_hit(r->scene, &h))
	{
		printf("No hit\n");
		return ;
	}
	change(r, h.o, h);
}