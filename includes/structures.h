#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "minirt.h"

typedef enum s_type
{
	A_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	TRIANGLE
}	t_type;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_sphere
{
	t_vector	coord;
	double		diameter;
	t_rgb		rgb;
}	t_sphere;

typedef struct	s_plane
{
	t_vector	coord;
	t_vector	origin;
	t_rgb		rgb;
}	t_plane;

typedef	struct	s_cylinder
{
	t_vector	coord;
	t_vector	orig;
	double		diameter;
	double		height;
	t_rgb		rgb;
}	t_cylinder;

union	s_objects
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_objects;

#endif
