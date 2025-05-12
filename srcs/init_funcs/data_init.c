#include "minirt.h"

t_data	*init_data(char* line)
{
	t_data	*data = ft_calloc(1, sizeof(t_data));
	data->file = line;
	return (data);
}
