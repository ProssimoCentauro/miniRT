#include "minirt.h"

int		launch_error(int error, char *line1, char *line2)
{
	print_error(line1, line2);
	return (error);
}

void	print_error(char *line1, char *line2)
{
	if (line1)
		ft_putstr_fd(line1, STDERR_FILENO);
	if (line2)
		ft_putstr_fd(line2, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}

void	exit_error(t_renderer *r, char *l1, char *l2)
{
	print_error(l1, l2);
	free_renderer(r);
	exit(EXIT_FAILURE);
}
