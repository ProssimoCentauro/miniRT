#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

#include "structures.h"

// Reset
#define RESET       "\x1b[0m"

// Bold colors
#define BOLD_BLACK  "\x1b[1;30m"
#define BOLD_RED    "\x1b[1;31m"
#define BOLD_GREEN  "\x1b[1;32m"
#define BOLD_YELLOW "\x1b[1;33m"
#define BOLD_BLUE   "\x1b[1;34m"
#define BOLD_MAGENTA "\x1b[1;35m"
#define BOLD_CYAN   "\x1b[1;36m"
#define BOLD_WHITE  "\x1b[1;37m"




//debug_utils.c
void print_object_data(t_object_data obj);

//figures_funcs.c
t_object *create_sphere(t_object_data *d);
t_object *create_plane(t_object_data *d);
t_object *create_cylinder(t_object_data *d);

//environment_objects_funcs.c
t_camera *create_camera(t_object_data *d);
t_light *create_light(t_object_data *d);
t_ambient *create_ambient(t_object_data *d);

//general_funcs.c
t_type	create_from_data(t_object_data *d, void **out);

//free_utils.c
void	free_mlx(t_mlx *mlx);
void	free_scene(t_scene *scene);
void	free_data(t_data *data);
void	free_renderer(t_renderer *r);

//error_utils.c
int		launch_error(int error, char *line1, char *line2);
void	print_error(char *line1, char *line2);
void	exit_error(t_renderer *r, char *l1, char *l2);
//data_init.c
t_renderer	*init_renderer(char* line);

//check_file.c
int	check_file(t_renderer *r);
#endif
