/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:38 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/02 22:57:52 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_sphere(t_object_data *d)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = SPHERE;
	obj->figure.sphere.coord = d->coord;
	obj->figure.sphere.diameter = d->diameter;
	obj->figure.sphere.rgb = d->rgb;
	return (obj);
}

t_object	*create_plane(t_object_data *d)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = PLANE;
	obj->figure.plane.coord = d->coord;
	obj->figure.plane.normal = d->normal;
	obj->figure.plane.rgb = d->rgb;
	return (obj);
}

t_object	*create_cylinder(t_object_data *d)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = CYLINDER;
	obj->figure.cylinder.coord = d->coord;
	obj->figure.cylinder.normal = d->normal;
	obj->figure.cylinder.diameter = d->diameter;
	obj->figure.cylinder.height = d->height;
	obj->figure.cylinder.rgb = d->rgb;
	return (obj);
}

t_object	*create_cone(t_object_data *d)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = CONE;
	obj->figure.cone.coord = d->coord;
	obj->figure.cone.normal = d->normal;
	obj->figure.cone.angle = d->angle;
	obj->figure.cone.height = d->height;
	obj->figure.cone.rgb = d->rgb;
	return (obj);
}
