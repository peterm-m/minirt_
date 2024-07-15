/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:46:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/15 19:51:52 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//static void	log_shader(t_render *r, t_hit *h)
//{
//	int	i;
//	t_object  *o;
//
//	i = -1;
//	while (r->scene->l[++i])
//	{
//		printf("--------------------------------- Test Light ---------------------------------\n");
//		log_light(r->scene->l[i]);
//		secundary_ray(h->pos, r->scene->l[i]->pos, &h->secundary);
//		printf("secundary ");
//		log_ray(&h->secundary);
//		if ((o = in_shadow(r->scene, h)))
//		{
//			log_object(o);
//			printf("--------------------------------- In shadow \n");
//			continue ;
//		}
//		printf("diffuse factor %f\n", ft_dotv3(h->secundary.d, h->normal));
//		printf("specular factor %f\n", -2.0f * ft_dotv3(h->secundary.d, h->normal) * ft_dotv3(h->primary.d, h->normal) + ft_dotv3(h->primary.d, h->secundary.d));
//		printf("---------------------------------\n");
//	}
//}

void	log_render(t_render *r, t_ivec2 pixel)
{
	t_hit	h;

	/* printf("--------------------------------- LOG RAY ---------------------------------\n");
	printf("Log ray in pixel = (%d, %d)\n\tprimary ", pixel.x, pixel.y);*/
	primary_ray(&pixel, r->scene->c, &h.primary); 
	//log_ray(&h.primary);
	first_hit(r->scene, &h);
	if (h.o == NULL)
	{
		printf("No hit\n");
		return ;
	}
	//surface_info(&h);
	//printf("Hit in t = %f; pos = (%f, %f, %f) with ",
	//h.primary.t, h.pos.x, h.pos.y, h.pos.z);
	printf(BHBLU"-------------------------------------------------------\n"END);
	printf(BHMAG"YOU SELECTED OBJECT: "END);
	log_object(h.o);
	printf(BHMAG"Select which attribute you want to change:\n"END);
	printf(BHRED"1. Position\n"BHGRN"2. Radius\n"BHBLU"3. Color\n");
	printf("-------------------------------------------------------\n"END);
	char buf[13];
	int readed = read(0, buf, sizeof(buf) - 1);
	if (readed < 0)
		printf(BHRED"ERROR LECTURA!!!"END);
	buf[readed] = '\0';
	if (ft_strncmp(buf, "1", 1) == 0)
	{
		printf("Enter the new Position in the next format: x y z\n");
		char buf1[103];
		int readed1 = read(0, buf1, sizeof(buf1) - 1);
		if (readed1 < 0)
			printf(BHRED"ERROR LECTURA!!!"END);
		buf1[readed1] = '\0';
		printf("new position: %s\n", buf1);
		char **xyz = ft_split(buf1, ' ');
		ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
		h.o->obj.sp.center = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	}
	else if (ft_strncmp(buf, "2", 1) == 0)
	{
		printf("Enter the new Radius in the next format: r\n");
		char buf2[103];
		int readed2 = read(0, buf2, sizeof(buf2) - 1);
		if (readed2 < 0)
			printf(BHRED"ERROR LECTURA!!!"END);
		buf2[readed2] = '\0';
		printf("new radius: %s\n", buf2);
		ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
		h.o->obj.sp.r = ft_atof(buf2);
	}
	else if (ft_strncmp(buf, "3", 1) == 0)
	{
		printf("Enter the new Color in the next format: r g b\n");
		char buf3[103];
		int readed3 = read(0, buf3, sizeof(buf3) - 1);
		if (readed3 < 0)
			printf(BHRED"ERROR LECTURA!!!"END);
		buf3[readed3] = '\0';
		printf("new color: %s\n", buf3);
		ft_bzero(r->canvas->data, WIN1_SY * r->canvas->sl + WIN1_SX * r->canvas->bpp);
		char **rgba = ft_split(buf3, ' ');
		h.o->color = ft_vec4(ft_atof(rgba[0])/255.0, ft_atof(rgba[1])/255.0, ft_atof(rgba[2])/255.0, 1.0);
	}
	else
		printf("REPETIR!!!!: %s", buf);
	buf[0] = '\0';
	//printf("\tn = (%f, %f, %f); texture = (%f, %f)\n", h.normal.x, h.normal.y, h.normal.z, h.texture.x, h.texture.y);
	//log_shader(r, &h);
}
