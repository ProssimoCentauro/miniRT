#include "minirt.h"

void	free_mlx(t_mlx *mlx)
{
	free(mlx);
}

void	free_scene(t_scene *scene)
{
	free(scene);
}

void	free_data(t_data *data)
{
	free(data);
}

void	free_renderer(t_renderer *r)
{
	free_mlx(r->mlx);
	free_scene(r->scene);
	free_data(r->data);
	free(r);
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
