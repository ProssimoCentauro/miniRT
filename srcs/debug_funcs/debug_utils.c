/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:21:57 by ibrunial          #+#    #+#             */
/*   Updated: 2025/10/11 16:21:58 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

const char	*get_type_name(t_type type)
{
	if (type == SPHERE)
		return ("SPHERE");
	if (type == PLANE)
		return ("PLANE");
	if (type == CYLINDER)
		return ("CYLINDER");
	if (type == CAMERA)
		return ("CAMERA");
	if (type == LIGHT)
		return ("LIGHT");
	if (type == A_LIGHT)
		return ("AMBIENT LIGHT");
	return ("UNKNOWN");
}

void	print_vec(t_vector v)
{
	printf("x: %.2f, y: %.2f, z: %.2f", v.x, v.y, v.z);
}

void	print_rgb(t_rgb color)
{
	printf("r: %d, g: %d, b: %d", color.r, color.g, color.b);
}

void	print_object_data(t_object_data obj)
{
	printf(BOLD_YELLOW "--START OBJECT DATA INFO--" RESET "\n");
	printf("Type: %s\n", get_type_name(obj.type));
	printf("Coordinates: ");
	print_vec(obj.coord);
	printf("\n");
	printf("Normal: ");
	print_vec(obj.normal);
	printf("\n");
	printf("Diameter: %.2f\n", obj.diameter);
	printf("Height: %.2f\n", obj.height);
	printf("RGB: ");
	print_rgb(obj.rgb);
	printf("\n");
	printf("FOV: %.2f\n", obj.fov);
	printf("Ratio: %.2f\n", obj.ratio);
	printf("Brightness: %.2f\n", obj.brightness);
	printf(BOLD_YELLOW "--------------------------" RESET "\n\n");
}
