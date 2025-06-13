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
