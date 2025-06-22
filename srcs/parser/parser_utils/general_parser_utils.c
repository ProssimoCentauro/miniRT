/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_parser_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:27:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/17 16:18:42 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_atod(char *str)
{
	double	res;
	size_t	i;
	size_t	j;
	int		sign;

	i = 0;
	j = 1;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + (str[i++] - '0');
	if (str[i++] == '\0')
		return (res * sign);
	while (str[i])
	{
		res += ((str[i++] - '0') / pow(10, j));
		j++;
	}
	return (res * sign);
}

size_t	count_lines(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

void	modify_vector(t_vector *v, double num, int i)
{
	if (i == 0)
		v->x = num;
	else if (i == 1)
		v->y = num;
	else if (i == 2)
		v->z = num;
}

void	modify_rgb(t_rgb *rgb, int num, int i)
{
	if (i == 0)
		rgb->r = num;
	else if (i == 1)
		rgb->g = num;
	else if (i == 2)
		rgb->b = num;
}
