#include "minirt.h"

void menu(t_render *r, t_ivec2 pixel)
{
	t_hit	h;

	primary_ray(&pixel, r->scene->c, &h.primary); 
	first_hit(r->scene, &h);
	if (h.o == NULL)
	{
		printf("No hit\n");
		return ;
	}
	change(r, h.o, h);
}