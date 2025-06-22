/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:43 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/16 19:51:44 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_type	create_from_data(t_object_data *d, void **out)
{
	if (!d || !out)
		return (1);
	*out = NULL;
	if (d->type == A_LIGHT)
		*out = create_ambient(d);
	else if (d->type == CAMERA)
		*out = create_camera(d);
	else if (d->type == LIGHT)
		*out = create_light(d);
	else if (d->type == SPHERE)
		*out = create_sphere(d);
	else if (d->type == PLANE)
		*out = create_plane(d);
	else if (d->type == CYLINDER)
		*out = create_cylinder(d);
	else
		return (1);
	if (!*out)
		return (launch_error(1, MALLOC_ERROR, NULL, NULL));
	return (d->type);
}
