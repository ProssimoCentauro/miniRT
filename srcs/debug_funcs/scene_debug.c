/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:21:06 by ibrunial          #+#    #+#             */
/*   Updated: 2025/10/11 16:21:41 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

const char	*type_name(t_type t)
{
	if (t == A_LIGHT)
		return ("Ambient Light");
	if (t == CAMERA)
		return ("Camera");
	if (t == LIGHT)
		return ("Light");
	if (t == SPHERE)
		return ("Sphere");
	if (t == PLANE)
		return ("Plane");
	if (t == CYLINDER)
		return ("Cylinder");
	if (t == CONE)
		return ("Cone");
	if (t == TRIANGLE)
		return ("Triangle");
	return ("Unknown");
}

void	print_scene(const t_scene *s)
{
	if (!s)
		return ;
	print_camera(s->cam);
	print_ambient(s->amb);
	print_lights(s->lights);
	print_objects(s->objs);
}
