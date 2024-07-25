#include "minirt.h"

void	menu(t_render *r, t_ivec2 pixel)
{
	t_hit	h;
printf("%s:%d \n", __FILE__, __LINE__);
	gen_camray(&pixel, r->scene->c, &h.primary); 
	if (!check_hit(r->scene, &h))
	{printf("%s:%d \n", __FILE__, __LINE__);
		printf("No hit\n");
		return ;
	}printf("%s:%d \n", __FILE__, __LINE__);
	while (1)
	{printf("%s:%d \n", __FILE__, __LINE__);
		if (change(r, h) == EXIT_SUCCESS)
		{
			printf(BHGRN"Changes added successfully\n"END);
			return ;
		}
		printf(BHRED"Changes could not be added, try again"END);
	}

}