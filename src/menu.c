#include "minirt.h"

void	menu(t_render *r, t_ivec2 pixel)
{
	t_hit	h;

	gen_camray(&pixel, r->scene->c, &h.primary); 
	if (!check_hit(r->scene, &h))
	{
		printf("No hit\n");
		return ;
	}
	while (1)
	{
		if (change(r, h) == EXIT_SUCCESS)
		{
			bound_object(h.o);
			ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
			printf(BHGRN"Changes added successfully\n"END);
			return ;
		}
		printf(BHRED"Changes could not be added, try again"END);
	}

}