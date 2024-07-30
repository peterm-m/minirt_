#include "minirt.h"

int change_ka(t_hit h)
{
    char    *inp;
    char    **rgba;
    t_vec4  colors;

    printf("Actual Ambient reflectivity: (%f,%f,%f)\nEnter the new one in the "\
    "next format: r,g,b\n", rint(h.o->material.k_a.x * 255.0f),
    rint(h.o->material.k_a.y * 255.0f), rint(h.o->material.k_a.z * 255.0f));
    inp = read_param(50);
    rgba = ft_split(inp, ',');
    if (ft_lenarr((void **)rgba) != 3 || !in_range(ft_atof(rgba[0]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[1]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[2]), 255.0, 0.0))
        return (printf(BHRED"Invalid arguments\n"), EXIT_FAILURE);
    colors = ft_vec4(ft_atof(rgba[0]) / 255.0, ft_atof(rgba[1]) / 255.0,
		ft_atof(rgba[2]) / 255.0, 1.0);
	h.o->material.k_a = colors;
    return (EXIT_SUCCESS);
}

int change_kd(t_hit h)
{
    char    *inp;
    char    **rgba;
    t_vec4  colors;

    printf("Actual Diffuse reflectivity: (%f,%f,%f)\nEnter the new one in the "\
    "next format: 'r,g,b'\n", rint(h.o->material.k_d.x * 255.0f),
    rint(h.o->material.k_d.y * 255.0f), rint(h.o->material.k_d.z * 255.0f));
    inp = read_param(50);
    rgba = ft_split(inp, ',');
    if (ft_lenarr((void **)rgba) != 3 || !in_range(ft_atof(rgba[0]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[1]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[2]), 255.0, 0.0))
        return (printf(BHRED"Invalid arguments\n"), EXIT_FAILURE);
    colors = ft_vec4(ft_atof(rgba[0]) / 255.0, ft_atof(rgba[1]) / 255.0,
		ft_atof(rgba[2]) / 255.0, 1.0);
	h.o->material.k_d = colors;
    return (EXIT_SUCCESS);
}
int change_ks(t_hit h)
{
    char    *inp;
    char    **rgba;
    t_vec4  colors;

    printf("Actual Diffuse reflectivity: (%f,%f,%f)\nEnter the new one in the "\
    "next format: 'r,g,b'\n", rint(h.o->material.k_s.x * 255.0f),
    rint(h.o->material.k_s.y * 255.0f), rint(h.o->material.k_s.z * 255.0f));
    inp = read_param(50);
    rgba = ft_split(inp, ',');
    if (ft_lenarr((void **)rgba) != 3 || !in_range(ft_atof(rgba[0]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[1]), 255.0, 0.0)
		|| !in_range(ft_atof(rgba[2]), 255.0, 0.0))
        return (printf(BHRED"Invalid arguments\n"), EXIT_FAILURE);
    colors = ft_vec4(ft_atof(rgba[0]) / 255.0, ft_atof(rgba[1]) / 255.0,
		ft_atof(rgba[2]) / 255.0, 1.0);
	h.o->material.k_s = colors;
    return (EXIT_SUCCESS);
}

int change_gls(t_hit h)
{
    char    *inp;
    float   g;

    printf("Actual Glosiness: %f\nEnter the new one in the "\
    "next range: 0 - 10.000\n", rint(h.o->material.glossiness));
    inp = read_param(50);
    if (!in_range(ft_atof(inp), 10000.0, 0.0))
        return (printf(BHRED"Invalid arguments\n"), EXIT_FAILURE);
    g = ft_atof(inp);
	h.o->material.glossiness = g;
    return (EXIT_SUCCESS);
}

int change_material(t_hit h)
{
    int inp;
    
    printf(BHMAG"\n*** You are in Change Material Mode ***\nSelect which"
    " attribute you want to change:\n\n"BHRED"0. Exit\n"BHCYN"1. Ambient reflectivity\n"BHGRN
    "2. Diffuse reflectivity\n"BHYEL"3. Specular reflectivity\n"BHWHT"4. Glosiness\n"
    BHMAG"5. Texture\n"BHBLU"6. Bump Map"END);
    inp = read_input(4);
    if (inp == 0)
		return (exit_menu());
	else if (inp == 1)
		return (change_ka(h));
	else if (inp == 2)
		return (change_kd(h));
	else if (inp == 3)
		return (change_ks(h));
	else if (inp == 4)
		return (change_gls(h));
    else if (inp == 5)
		return (change_texture(h));
    else if (inp == 6)
		return (change_bump(h));
    else
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
