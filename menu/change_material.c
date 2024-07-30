#include "minirt.h"

int change_ka(t_render *r, t_hit h)
{
    printf("Actual Ambient reflectivity: %f", h.color.a);
    return (EXIT_SUCCESS);
}

int change_material(t_render *r, t_hit h)
{
    int inp;

    (void)r;
    (void)h;
    
    printf(BHMAG"\n*** You are in Change Material Mode ***\nSelect which"
    " attribute you want to change:\n\n"BHRED"0. Exit\n"BHCYN"1. Ambient reflectivity\n"BHGRN
    "2. Diffuse reflectivity\n"BHYEL"3. Specular reflectivity\n"BHWHT"4. Glosiness\n"
    BHBLU"5. Texture\n\n"END);
    inp = read_input(4);
    if (inp == 0)
		return (exit_menu());
	else if (inp == 1)
		return (1);
	else if (inp == 2)
		return (2);
	else if (inp == 3)
		return (3);
	else if (inp == 4)//TODO: env
		return (4);
    return (EXIT_SUCCESS);
}