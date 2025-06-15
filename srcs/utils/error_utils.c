#include "minirt.h"

int		launch_error(int error, char *line1, char *line2, char *line3)
{
	print_error(line1, line2, line3);
	return (error);
}

void	print_error(char *line1, char *line2, char *line3)
{
	if (line1)
		ft_putstr_fd(line1, STDERR_FILENO);
	if (line2)
		ft_putstr_fd(line2, STDERR_FILENO);
	if (line3)
		ft_putstr_fd(line3, STDERR_FILENO);
	if (line1 || line2 || line3)
	write(STDERR_FILENO, "\n", 1);
}

void	exit_error(t_renderer *r, char *l1, char *l2, char *l3)
{
	print_error(l1, l2, l3);
	free_renderer(r);
	exit(EXIT_FAILURE);
}
