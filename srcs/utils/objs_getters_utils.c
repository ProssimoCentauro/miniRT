/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_getters_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:21:30 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/18 11:21:31 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*get_obj_coord(t_object *obj)
{
	if (!obj)
		return (NULL);
	if (obj->type == SPHERE)
		return (&obj->figure.sphere.coord);
	if (obj->type == PLANE)
		return (&obj->figure.plane.coord);
	if (obj->type == CYLINDER)
		return (&obj->figure.cylinder.coord);
	if (obj->type == CONE)
		return (&obj->figure.cone.coord);
	return (NULL);
}

t_vector	*get_obj_normal(t_object *obj)
{
	if (!obj)
		return (NULL);
	if (obj->type == PLANE)
		return (&obj->figure.plane.normal);
	if (obj->type == CYLINDER)
		return (&obj->figure.cylinder.normal);
	if (obj->type == CONE)
		return (&obj->figure.cone.normal);
	return (NULL);
}
