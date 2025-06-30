#include "minirt.h"

int	exit_handler(t_renderer *r)
{
	free_renderer(r);
	exit(EXIT_SUCCESS);
	return (0);
}

int	events_handler(int key, t_renderer *r)
{
	printf("key: %d\n", key);
	if (key == 65307)
		exit_handler(r);
	return (0);
}
