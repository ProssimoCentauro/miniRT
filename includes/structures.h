/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:53:03 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/15 15:46:39 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "minirt.h"
# include "../libft/header_files/vector.h"

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
}						t_type;


typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

// typedef union u_rgb
// {
// 	struct
// 	{
// 		unsigned char	r;
// 		unsigned char	g;
// 		unsigned char	b;
// 		unsigned char	t;
// 	};
// 	uint32_t			rgb;
// }						t_rgb;


// spostato in vector.h
// typedef struct s_vector
// {
// 	double			x;
// 	double			y;
// 	double			z;
// }					t_vector;

typedef struct s_object_data
{
	t_type				type;
	t_vector			coord;
	t_vector			normal;
	double				diameter;
	double				height;
	double				angle;
	t_rgb				rgb;
	double				fov;
	double				ratio;
	double				brightness;
}						t_object_data;

typedef struct s_sphere
{
	t_vector			coord;
	double				diameter;
	t_rgb				rgb;
}						t_sphere;

typedef struct s_plane
{
	t_vector			coord;
	t_vector			normal;
	t_rgb				rgb;
}						t_plane;

typedef struct s_cylinder
{
	t_vector			coord;
	t_vector			normal;
	double				diameter;
	double				height;
	t_rgb				rgb;
}						t_cylinder;

typedef struct s_cone
{
	t_vector			coord;
	t_vector			normal;
	double				angle;
	double				height;
	t_rgb				rgb;
}						t_cone;

typedef struct s_circle
{
	t_vector			coord;
	t_vector			normal;
	double				radius_squared;
}						t_circle;

typedef union u_figures
{
	t_sphere			sphere;
	t_plane				plane;
	t_cylinder			cylinder;
	t_cone				cone;
}						t_figures;

typedef struct s_object
{
	t_type				type;
	t_figures			figure;
	struct s_object		*next;
}						t_object;

typedef struct s_camera
{
	t_type				type;
	t_vector			coord;
	t_vector			orientation;
    t_vector            right;
    t_vector            up;
    t_vector            vp_up_left;
    t_vector            px_step;
    t_vector            py_step;
	double				fov;
}						t_camera;

typedef struct s_ambient
{
	t_type				type;
	double				ratio;
	t_rgb				rgb;
}						t_ambient;

typedef struct s_light
{
	t_vector			coord;
	double				brightness;
	t_rgb				rgb;
	struct s_light		*next;
}						t_light;

typedef struct s_scene
{
	t_camera			*cam;
	t_ambient			*amb;
	t_light				*lights;
	t_object			*objs;
	t_object			*selected_obj;
}						t_scene;

typedef struct s_hit
{
	t_object			*obj;
	double				dist;
	t_vector			point;
	t_vector			normal;
	t_rgb				rgb;
}						t_hit;

typedef struct s_ray
{
	t_vector			direction;
	t_vector			coord;
	t_hit				hit;
}						t_ray;

typedef struct s_image
{
	void				*img;
	void				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_image;

typedef struct s_mlx
{
	void				*mlx_instance;
	void				*window;
	int					width;
	int					height;
	t_image				image;
}						t_mlx;

typedef struct s_data
{
	char				*file;
	int					cameras;
	int					a_lights;
	t_object_data		obj_data;
}						t_data;

typedef struct s_renderer
{
	t_data				*data;
	t_mlx				*mlx;
	t_scene				*scene;
}						t_renderer;

typedef struct s_equation
{
	double				a;
	double				b;
	double				c;
	double				t;
}						t_equation;


#endif
