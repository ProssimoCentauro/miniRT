#include "minirt.h"

int	check_ratio(char *ratio, double *num)
{
	if (ratio[0] == '0')
	{
		if (ratio[1] != '.')
			return (1);
		if (ratio[2] < '0' && ratio[2] > '9')
			return (1);
	}
	else if (ratio[0] == '1')
	{
		if (ratio[1] != '.')
			return (1);
		if (ratio[2] != '0')
			return (1);
	}
	else
		return (1);
	*num = ft_atod(ratio);
	return (0);
}

int  check_fov(char *line, double *num)
{
	int res;

	if (is_valid_integer(line))
		return (1);
	res = ft_atoi(line);
	if (res < 0 || res > 180)
		return (1);
	*num = ft_atod(line);
	return (0);
}
