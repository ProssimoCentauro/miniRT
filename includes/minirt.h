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



typedef struct s_object
{
	t_type	type;
	void	*obj;
}	t_object;

typedef struct s_data
{
	char *file;

}	t_data;

//error_utils.c
void	print_error(char *line1, char *line2);
void	exit_error(t_data *data, char *l1, char *l2);
void	free_data(t_data *data);
//data_init.c
t_data	*init_data(char* line);

//check_file.c
int	check_file(t_data *data);
#endif
