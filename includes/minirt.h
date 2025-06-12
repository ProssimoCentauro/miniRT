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





//error_utils.c
void	print_error(char *line1, char *line2);
void	exit_error(t_renderer *r, char *l1, char *l2);
void	free_renderer(t_renderer *renderer);
//data_init.c
t_renderer	*init_renderer(char* line);

//check_file.c
int	check_file(t_renderer *r);
#endif
