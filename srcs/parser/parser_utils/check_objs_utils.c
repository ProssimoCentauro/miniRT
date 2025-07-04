/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:44:03 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/04 14:20:04 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

# define EM_COLOR_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid emission color for "
# define EM_STRENGHT "\x1b[1;31m⬤ \x1b[0mInvalid emission strenght for "

int	check_sphere(char **line, t_renderer *r)
{
	t_object		*sp;
	t_object_data	data;

    ft_memset(&data, 0, sizeof(t_object_data));
	data.type = SPHERE;
	if (count_lines(line) != 4 && count_lines(line) != 6)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, SP_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, SP_MSG));
	if (is_valid_double(line[2], &(data).diameter))
		return (launch_error(1, SYNTAX_ERROR, DIAMETER_ERROR, SP_MSG));
	if (check_colors(line[3], &(data).material.color))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, SP_MSG));
    if (count_lines(line) == 6)
    {
        if (is_valid_double(line[4], &(data).material.em_strenght))
            return (launch_error(1, SYNTAX_ERROR, EM_STRENGHT, SP_MSG));
        if (check_colors(line[5], &(data).material.em_color))
            return (launch_error(1, SYNTAX_ERROR, EM_COLOR_ERROR, SP_MSG));
    }
	create_from_data(&data, (void **)&sp);
	add_object(r->scene, sp);
	return (0);
}

int	check_plane(char **line, t_renderer *r)
{
	t_object		*pl;
	t_object_data	data;

    ft_memset(&data, 0, sizeof(t_object_data));
	data.type = PLANE;
	if (count_lines(line) != 4 && count_lines(line) != 6)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, PL_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, PL_MSG));
	if (check_normal(line[2], &(data).normal))
		return (launch_error(1, SYNTAX_ERROR, NORMAL_ERROR, PL_MSG));
	if (check_colors(line[3], &(data).material.color))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, PL_MSG));
    if (count_lines(line) == 6)
    {
        if (is_valid_double(line[4], &(data).material.em_strenght))
            return (launch_error(1, SYNTAX_ERROR, EM_STRENGHT, SP_MSG));
        if (check_colors(line[5], &(data).material.em_color))
            return (launch_error(1, SYNTAX_ERROR, EM_COLOR_ERROR, SP_MSG));
    }
	create_from_data(&data, (void **)&pl);
	add_object(r->scene, pl);
	return (0);
}

int	check_cylinder(char **line, t_renderer *r)
{
	t_object		*cy;
	t_object_data	data;

	data.type = CYLINDER;
	if (count_lines(line) != 6 && count_lines(line) != 8)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, CY_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, CY_MSG));
	if (check_normal(line[2], &(data).normal))
		return (launch_error(1, SYNTAX_ERROR, NORMAL_ERROR, CY_MSG));
	if (is_valid_double(line[3], &(data).diameter))
		return (launch_error(1, SYNTAX_ERROR, DIAMETER_ERROR, CY_MSG));
	if (is_valid_double(line[4], &(data).height))
		return (launch_error(1, SYNTAX_ERROR, HEIGHT_ERROR, CY_MSG));
	if (check_colors(line[5], &(data).material.color))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, CY_MSG));
    if (count_lines(line) == 8)
    {
        if (is_valid_double(line[6], &(data).material.em_strenght))
            return (launch_error(1, SYNTAX_ERROR, EM_STRENGHT, SP_MSG));
        if (check_colors(line[7], &(data).material.em_color))
            return (launch_error(1, SYNTAX_ERROR, EM_COLOR_ERROR, SP_MSG));
    }
	create_from_data(&data, (void **)&cy);
	add_object(r->scene, cy);
	return (0);
}

int	check_cone(char **line, t_renderer *r)
{
	t_object		*co;
	t_object_data	data;

	data.type = CONE;
	if (count_lines(line) != 6 && count_lines(line) != 8)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, CO_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, CO_MSG));
	if (check_normal(line[2], &(data).normal))
		return (launch_error(1, SYNTAX_ERROR, NORMAL_ERROR, CO_MSG));
	if (is_valid_angle(line[3], &(data).angle))
		return (launch_error(1, SYNTAX_ERROR, ANGLE_ERROR, CO_MSG));
	if (is_valid_double(line[4], &(data).height))
		return (launch_error(1, SYNTAX_ERROR, HEIGHT_ERROR, CO_MSG));
	if (check_colors(line[5], &(data).material.color))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, CO_MSG));
    if (count_lines(line) == 8)
    {
        if (is_valid_double(line[6], &(data).material.em_strenght))
            return (launch_error(1, SYNTAX_ERROR, EM_STRENGHT, SP_MSG));
        if (check_colors(line[7], &(data).material.em_color))
            return (launch_error(1, SYNTAX_ERROR, EM_COLOR_ERROR, SP_MSG));
    }
	create_from_data(&data, (void **)&co);
	add_object(r->scene, co);
	return (0);
}
