/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:13:02 by pedromar          #+#    #+#             */
/*   Updated: 2024/08/04 16:09:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef float	t_real;

typedef union u_vec2
{
	struct
	{
		t_real	x;
		t_real	y;
	};
	struct
	{
		t_real	u;
		t_real	v;
	};
	struct
	{
		t_real	left;
		t_real	right;
	};
	struct
	{
		t_real	width;
		t_real	height;
	};
	t_real	elements[2];
}	t_vec2;

typedef union u_ivec2
{
	struct	
	{
		int	i;
		int	j;
	};
	struct
	{
		int	x;
		int	y;
	};
}	t_ivec2;

typedef union u_matrix2
{
	t_real	elements[2][2];
	t_vec2	columns[2];
}	t_matrix2;

typedef union u_vec3
{
	struct
	{
		t_real	x;
		t_real	y;
		t_real	z;
	};
	struct
	{
		t_real	u;
		t_real	v;
		t_real	w;
	};
	struct
	{
		t_real	r;
		t_real	g;
		t_real	b;
	};
	struct
	{
		t_vec2	xy;
		t_real	nothing1;
	};
	struct
	{
		t_real	nothing2;
		t_vec2	yz;
	};
	struct
	{
		t_vec2	uv;
		t_real	nothing3;
	};
	struct
	{
		t_real	nothing4;
		t_vec2	vw;
	};
	t_real	elements[3];
}	t_vec3;

typedef union u_ivec3
{
	struct	
	{
		int	i;
		int	j;
		int	k;
	};
	struct
	{
		int	x;
		int	y;
		int	z;
	};
}	t_ivec3;

typedef union u_matrix3
{
	t_real	elements[3][3];
	t_vec3	columns[3];
}	t_matrix3;

typedef union u_vec4
{
	struct
	{
		union
		{
			t_vec3	xyz;
			struct
			{
				t_real	x;
				t_real	y;
				t_real	z;
			};
		};
		t_real	w;
	};
	struct
	{
		union
		{
			t_vec3	rgb;
			struct
			{
				t_real	r;
				t_real	g;
				t_real	b;
			};
		};
		t_real	a;
	};
	struct
	{
		t_vec2	xy;
		t_real	nothing1;
		t_real	nothing2;
	};
	struct
	{
		t_real	nothing3;
		t_vec2	yz;
		t_real	nothing4;
	};
	struct
	{
		t_real	nothing5;
		t_real	nothing6;
		t_vec2	zw;
	};
	t_real	elements[4];
}	t_vec4;

typedef union u_ivec4
{
	struct	
	{
		int	i;
		int	j;
		int	k;
		int	l;
	};
	struct
	{
		int	x;
		int	y;
		int	z;
		int	w;
	};
}	t_ivec4;

typedef union u_matrix4
{
	t_real	elements[4][4];
	t_vec4	columns[4];
}	t_matrix4;

/// creation
t_vec2		ft_vec2(t_real x, t_real y);
t_vec3		ft_vec3(t_real x, t_real y, t_real z);
t_vec4		ft_vec4(t_real x, t_real y, t_real z, t_real w);

t_matrix2	ft_mat2(void );
t_matrix3	ft_mat3(void );
t_matrix4	ft_mat4(void );

t_matrix2	ft_ident2(void );
t_matrix3	ft_ident3(void );
t_matrix4	ft_ident4(void );

// binary
t_vec4		ft_linear_combv4m4(t_vec4 v, t_matrix4 m);

t_vec2		ft_addv2(t_vec2 v1, t_vec2 v2);
t_vec3		ft_addv3(t_vec3 v1, t_vec3 v2);
t_vec4		ft_addv4(t_vec4 v1, t_vec4 v2);

t_matrix2	ft_addm2(t_matrix2 m1, t_matrix2 m2);
t_matrix3	ft_addm3(t_matrix3 m1, t_matrix3 m2);
t_matrix4	ft_addm4(t_matrix4 m1, t_matrix4 m2);

t_vec2		ft_subv2(t_vec2 v1, t_vec2 v2);
t_vec3		ft_subv3(t_vec3 v1, t_vec3 v2);
t_vec4		ft_subv4(t_vec4 v1, t_vec4 v2);

t_matrix2	ft_subm2(t_matrix2 a, t_matrix2 b);
t_matrix3	ft_subm3(t_matrix3 a, t_matrix3 b);
t_matrix4	ft_subm4(t_matrix4 a, t_matrix4 b);

t_vec2		ft_mulv2v(t_vec2 v1, t_vec2 v2);
t_vec3		ft_mulv3v(t_vec3 v1, t_vec3 v2);
t_vec4		ft_mulv4v(t_vec4 v1, t_vec4 v2);

t_vec2		ft_mulm2v(t_matrix2 m, t_vec2 v);
t_vec3		ft_mulm3v(t_matrix3 m, t_vec3 v);
t_vec4		ft_mulm4v(t_matrix4 m, t_vec4 v);

t_matrix2	ft_mulm2m(t_matrix2 m1, t_matrix2 m2);
t_matrix3	ft_mulm3m(t_matrix3 m1, t_matrix3 m2);
t_matrix4	ft_mulm4m(t_matrix4 m1, t_matrix4 m2);

t_vec2		ft_mulv2f(t_vec2 v, t_real f);
t_vec3		ft_mulv3f(t_vec3 v, t_real f);
t_vec4		ft_mulv4f(t_vec4 v, t_real f);

t_matrix2	ft_mulm2f(t_matrix2 m, t_real f);
t_matrix3	ft_mulm3f(t_matrix3 m, t_real f);
t_matrix4	ft_mulm4f(t_matrix4 m, t_real f);

t_vec2		ft_divv2f(t_vec2 v, t_real f);
t_vec3		ft_divv3f(t_vec3 v, t_real f);
t_vec4		ft_divv4f(t_vec4 v, t_real f);

t_matrix2	ft_divm2f(t_matrix2 m, t_real f);
t_matrix3	ft_divm3f(t_matrix3 m, t_real f);
t_matrix4	ft_divm4f(t_matrix4 m, t_real f);

t_real		ft_dotv2(t_vec2 v1, t_vec2 v2);
t_real		ft_dotv3(t_vec3 v1, t_vec3 v2);
t_real		ft_dotv4(t_vec4 v1, t_vec4 v2);

t_vec3		ft_cross(t_vec3 v1, t_vec3 v2);

// ternary
t_vec2		ft_fmav2f(t_vec2 a, t_real t, t_vec2 b);
t_vec3		ft_fmav3f(t_vec3 a, t_real t, t_vec3 b);
t_vec4		ft_fmav4f(t_vec4 a, t_real t, t_vec4 b);

t_vec2		ft_fmav2v(t_vec2 a, t_vec2 t, t_vec2 b);
t_vec3		ft_fmav3v(t_vec3 a, t_vec3 t, t_vec3 b);
t_vec4		ft_fmav4v(t_vec4 a, t_vec4 t, t_vec4 b);

t_matrix2	ft_fmam2m(t_matrix2 a, t_matrix2 t, t_matrix2 b);
t_matrix3	ft_fmam3m(t_matrix3 a, t_matrix3 t, t_matrix3 b);
t_matrix4	ft_fmam4m(t_matrix4 a, t_matrix4 t, t_matrix4 b);

t_matrix2	ft_fmam2f(t_matrix2 a, t_real t, t_matrix2 b);
t_matrix3	ft_fmam3f(t_matrix3 a, t_real t, t_matrix3 b);
t_matrix4	ft_fmam4f(t_matrix4 a, t_real t, t_matrix4 b);

// unary
t_real		ft_lensqrv2(t_vec2 v);
t_real		ft_lensqrv3(t_vec3 v);
t_real		ft_lensqrv4(t_vec4 v);

t_real		ft_lenv2(t_vec2 v);
t_real		ft_lenv3(t_vec3 v);
t_real		ft_lenv4(t_vec4 v);

t_vec2		ft_normv2(t_vec2 v);
t_vec3		ft_normv3(t_vec3 v);
t_vec4		ft_normv4(t_vec4 v);

t_matrix2	ft_transposem2(t_matrix2 m);
t_matrix3	ft_transposem3(t_matrix3 m);
t_matrix4	ft_transposem4(t_matrix4 m);

// logic
bool		ft_eqv2(t_vec2 v1, t_vec2 v2);
bool		ft_eqv3(t_vec3 v1, t_vec3 v2);
bool		ft_eqv4(t_vec4 v1, t_vec4 v2);

bool		ft_eqm2(t_matrix2 v1, t_matrix2 v2);
bool		ft_eqm3(t_matrix3 v1, t_matrix3 v2);
bool		ft_eqm4(t_matrix4 v1, t_matrix4 v2);

bool		ft_minv2(t_vec2 v1, t_vec2 v2);
bool		ft_minv3(t_vec3 v1, t_vec3 v2);
bool		ft_minv4(t_vec4 v1, t_vec4 v2);

// utils
t_vec2		ft_toeachv2(t_vec2 v, t_real (*f)(t_real));
t_vec3		ft_toeachv3(t_vec3 v, t_real (*f)(t_real));
t_vec4		ft_toeachv4(t_vec4 v, t_real (*f)(t_real));

t_matrix2	ft_toeachm2(t_matrix2 m, t_real (*f)(t_real));
t_matrix3	ft_toeachm3(t_matrix3 m, t_real (*f)(t_real));
t_matrix4	ft_toeachm4(t_matrix4 m, t_real (*f)(t_real));

void		printv2(t_vec2 v);
void		printv3(t_vec3 v);
void		printv4(t_vec4 v);

void		printm2(t_matrix2 m);
void		printm3(t_matrix3 m);
void		printm4(t_matrix4 m);

#endif