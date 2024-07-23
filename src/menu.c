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
	while (1)
	{
		if (change(r, h.o, h) == EXIT_SUCCESS)
		{
			printf(BHGRN"Changes added successfully\n"END);
			return ;
		}
		printf(BHRED"Changes could not be added, try again"END);
	}

}