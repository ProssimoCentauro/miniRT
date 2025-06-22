/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:44:03 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/17 16:44:04 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_sphere(char **line, t_renderer *r)
{
	t_object		*sp;
	t_object_data	data;

	data.type = SPHERE;
	if (count_lines(line) != 4)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, SP_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, SP_MSG));
	if (is_valid_double(line[2], &(data).diameter))
		return (launch_error(1, SYNTAX_ERROR, DIAMETER_ERROR, SP_MSG));
	if (check_colors(line[3], &(data).rgb))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, SP_MSG));
	create_from_data(&data, (void **)&sp);
	add_object(r->scene, sp);
	return (0);
}

int	check_plane(char **line, t_renderer *r)
{
	t_object		*pl;
	t_object_data	data;

	data.type = PLANE;
	if (count_lines(line) != 4)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, PL_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, PL_MSG));
	if (check_normal(line[2], &(data).normal))
		return (launch_error(1, SYNTAX_ERROR, NORMAL_ERROR, PL_MSG));
	if (check_colors(line[3], &(data).rgb))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, PL_MSG));
	create_from_data(&data, (void **)&pl);
	add_object(r->scene, pl);
	return (0);
}

int	check_cylinder(char **line, t_renderer *r)
{
	t_object		*cy;
	t_object_data	data;

	data.type = CYLINDER;
	if (count_lines(line) != 6)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, CY_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, CY_MSG));
	if (check_normal(line[2], &(data).normal))
		return (launch_error(1, SYNTAX_ERROR, NORMAL_ERROR, CY_MSG));
	if (is_valid_double(line[3], &(data).diameter))
		return (launch_error(1, SYNTAX_ERROR, DIAMETER_ERROR, CY_MSG));
	if (is_valid_double(line[4], &(data).height))
		return (launch_error(1, SYNTAX_ERROR, HEIGHT_ERROR, CY_MSG));
	if (check_colors(line[5], &(data).rgb))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, CY_MSG));
	create_from_data(&data, (void **)&cy);
	add_object(r->scene, cy);
	return (0);
}
