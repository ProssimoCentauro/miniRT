/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_checker_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:48:40 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/03 14:58:12 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	detect_checker(char **line, t_renderer *r)
{
	if (!ft_strncmp(*line, "A\0", 2))
		return (check_amb_light(line, r));
	if (!ft_strncmp(*line, "C\0", 2))
		return (check_camera(line, r));
	if (!ft_strncmp(*line, "L\0", 2))
		return (check_light(line, r));
	if (!ft_strncmp(*line, "sp\0", 3))
		return (check_sphere(line, r));
	if (!ft_strncmp(*line, "pl\0", 3))
		return (check_plane(line, r));
	if (!ft_strncmp(*line, "cy\0", 3))
		return (check_cylinder(line, r));
	if (!ft_strncmp(*line, "co\0", 3))
		return (check_cone(line, r));
	return (launch_error(1, SYNTAX_ERROR, INV_IDF, *line));
}

void	check_scene(t_renderer *r)
{
	t_scene	*s;

	s = r->scene;
	if (!s->cam && !s->amb && !s->objs && !s->lights)
		exit_error(r, GENERAL_ERROR, EMPTY_FILE_ERROR, NULL);
	else if (!s->cam)
		exit_error(r, SYNTAX_ERROR, MISSING_ERROR, CAM_MSG);
	else if (!s->amb)
		exit_error(r, SYNTAX_ERROR, MISSING_ERROR, A_LIGHT_MSG);
	else if (!s->lights)
		exit_error(r, SYNTAX_ERROR, MISSING_ERROR, LIGHT_MSG);
}

void	check_args(int ac, char *file)
{
	size_t	len;
	int		check;

	len = 0;
	check = 1;
	if (ac != 2)
	{
		print_error(ARGS_ERROR, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(file);
	check = file[len - 3] == '.' && file[len - 2] == 'r' && file[len
		- 1] == 't';
	if (len < 4)
		check = 0;
	if (!check)
	{
		print_error(NOT_RT_FILE_ERROR, NULL, NULL);
		exit(EXIT_FAILURE);
	}
}
