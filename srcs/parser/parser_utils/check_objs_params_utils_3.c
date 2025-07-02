/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs_params_utils_3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:43:57 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/02 22:54:18 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_fov(char *line, double *num)
{
	int	res;

	if (is_valid_integer(line))
		return (1);
	res = ft_atoi(line);
	if (res < 0 || res > 180)
		return (1);
	*num = ft_atod(line);
	return (0);
}

int	is_valid_angle(char* line, double *num)
{
	if (!is_valid_double(line, num))
	{
		if (*num > 0.0 && *num <= 90.0)
			return (0);
	}
	return (1);
}
