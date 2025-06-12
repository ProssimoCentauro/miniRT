#include "minirt.h"

t_renderer	*init_renderer(char* line)
{
	t_renderer	*r = ft_calloc(1, sizeof(t_renderer));
	r->data	= ft_calloc(1, sizeof(t_data));
	r->data->file = line;
	r->data->cameras = 0;
	return (r);
}
