
#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef union u_vec2
{
	struct
	{
		float	x;
		float	y;
	};
	struct
	{
		float	u;
		float	v;
	};
	struct
	{
		float	left;
		float	right;
	};
	struct
	{
		float	width;
		float	height;
	};
	float	elements[2];
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
	float	elements[2][2];
	t_vec2	columns[2];
}	t_matrix2;

typedef union u_vec3
{
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	struct
	{
		float	u;
		float	v;
		float	w;
	};
	struct
	{
		float	r;
		float	g;
		float	b;
	};
	struct
	{
		t_vec2	xy;
		float	nothing1;
	};
	struct
	{
		float	nothing2;
		t_vec2	yz;
	};
	struct
	{
		t_vec2	uv;
		float	nothing3;
	};
	struct
	{
		float	nothing4;
		t_vec2	vw;
	};
	float	elements[3];
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
	float	elements[3][3];
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
				float	x;
				float	y;
				float	z;
			};
		};
		float	w;
	};
	struct
	{
		union
		{
			t_vec3	rgb;
			struct
			{
				float	r;
				float	g;
				float	b;
			};
		};
		float	a;
	};
	struct
	{
		t_vec2	xy;
		float	nothing1;
		float	nothing2;
	};
	struct
	{
		float	nothing3;
		t_vec2	yz;
		float	nothing4;
	};
	struct
	{
		float	nothing5;
		float	nothing6;
		t_vec2	zw;
	};
	float	elements[4];
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
	float	elements[4][4];
	t_vec4	columns[4];
}	t_matrix4;

/// creation
t_vec2		ft_vec2(float x, float y);
t_vec3		ft_vec3(float x, float y, float z);
t_vec4		ft_vec4(float x, float y, float z, float w);

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

t_vec2		ft_mulv2f(t_vec2 v, float f);
t_vec3		ft_mulv3f(t_vec3 v, float f);
t_vec4		ft_mulv4f(t_vec4 v, float f);

t_matrix2	ft_mulm2f(t_matrix2 m, float f);
t_matrix3	ft_mulm3f(t_matrix3 m, float f);
t_matrix4	ft_mulm4f(t_matrix4 m, float f);

t_vec2		ft_divv2f(t_vec2 v, float f);
t_vec3		ft_divv3f(t_vec3 v, float f);
t_vec4		ft_divv4f(t_vec4 v, float f);

t_matrix2	ft_divm2f(t_matrix2 m, float f);
t_matrix3	ft_divm3f(t_matrix3 m, float f);
t_matrix4	ft_divm4f(t_matrix4 m, float f);

bool		ft_eqv2(t_vec2 v1, t_vec2 v2);
bool		ft_eqv3(t_vec3 v1, t_vec3 v2);
bool		ft_eqv4(t_vec4 v1, t_vec4 v2);

float		ft_dotv2(t_vec2 v1, t_vec2 v2);
float		ft_dotv3(t_vec3 v1, t_vec3 v2);
float		ft_dotv4(t_vec4 v1, t_vec4 v2);

t_vec3		ft_cross(t_vec3 v1, t_vec3 v2);
// unary
float		ft_lensqrv2(t_vec2 v);
float		ft_lensqrv3(t_vec3 v);
float		ft_lensqrv4(t_vec4 v);

float		ft_lenv2(t_vec2 v);
float		ft_lenv3(t_vec3 v);
float		ft_lenv4(t_vec4 v);

t_vec2		ft_normv2(t_vec2 v);
t_vec3		ft_normv3(t_vec3 v);
t_vec4		ft_normv4(t_vec4 v);

t_matrix2	ft_transposem2(t_matrix2 m);
t_matrix3	ft_transposem3(t_matrix3 m);
t_matrix4	ft_transposem4(t_matrix4 m);

// utils
void		printv2(t_vec2 v);
void		printv3(t_vec3 v);
void		printv4(t_vec4 v);

void		printm2(t_matrix2 m);
void		printm3(t_matrix3 m);
void		printm4(t_matrix4 m);

#endif