#include "minirt.h"

int	main(int ac, char **av)
{
	t_renderer	*renderer;

	check_args(ac, av[1]);

	renderer = init_renderer(av[1]);
	check_file(renderer);
	free_renderer(renderer);
	return (0);
}
