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
	t_vector	normal;
	t_rgb		rgb;
}	t_plane;

typedef	struct	s_cylinder
{
	t_vector	coord;
	t_vector	normal;
	double		diameter;
	double		height;
	t_rgb		rgb;
}	t_cylinder;

typedef union	u_figures
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_figures;

typedef struct	s_objects
{
	t_type		type;
	t_figures	figure;
	struct s_objects	*next;
}	t_objects;



typedef struct	s_camera
{
	t_type		type;
	t_vector	coord;
	t_vector	orientation;
	double			fov;
}	t_camera;

typedef	struct	s_ambient
{
	t_type	type;
	double	ratio;
	t_rgb	rgb;
}	t_ambient;

typedef	struct	s_light
{
	t_vector		coord;
	double			brightness;
	t_rgb			rgb;
	struct s_light	*next;
}	t_light;

typedef	struct	s_scene
{
	t_camera	cam;
	t_ambient	amb;
	t_light		*lights;
	t_objects	*objs;
}	t_scene;











#endif
