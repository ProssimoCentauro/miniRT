#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

#include "structures.h"
#include "defines.h"

//debug_utils.c
void print_object_data(t_object_data obj);
void print_scene(t_scene *scene);

//figures_funcs.c
t_object *create_sphere(t_object_data *d);
t_object *create_plane(t_object_data *d);
t_object *create_cylinder(t_object_data *d);

//environment_funcs.c
t_camera *create_camera(t_object_data *d);
t_light *create_light(t_object_data *d);
t_ambient *create_ambient(t_object_data *d);

//general_funcs.c
t_type	create_from_data(t_object_data *d, void **out);

//scene_utils.c	
void	add_object(t_scene *scene, t_object *new_obj);
void	add_light(t_scene *scene, t_light *new_light);

//free_utils.c
void	free_mlx(t_mlx *mlx);
void	free_scene(t_scene *scene);
void	free_data(t_data *data);
void	free_renderer(t_renderer *r);

//error_utils.c
int		launch_error(int error, char *line1, char *line2, char *line3);
void	print_error(char *line1, char *line2, char *line3);
void	exit_error(t_renderer *r, char *l1, char *l2, char *l3);
//data_init.c
t_renderer	*init_renderer(char* line);

//check_file.c
int	check_file(t_renderer *r);
#endif
