#include "minirt.h"

void	free_data(t_data *data)
{
	free(data);
}

void	print_error(char *line1, char *line2)
{
	if (line1)
		ft_putstr_fd(line1, STDERR_FILENO);
	if (line2)
		ft_putstr_fd(line2, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}

void	exit_error(t_data *data, char *l1, char *l2)
{
	print_error(l1, l2);
	free_data(data);
	exit(EXIT_FAILURE);
}
