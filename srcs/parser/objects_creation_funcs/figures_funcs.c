/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:38 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/04 14:30:39 by ibrunial         ###   ########.fr       */
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
    obj->figure.sphere.material.color = d->material.color;
    obj->figure.sphere.material.em_color = d->material.em_color;
    obj->figure.sphere.material.em_strenght = d->material.em_strenght;
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
    obj->figure.plane.material.color = d->material.color;
    obj->figure.plane.material.em_color = d->material.em_color;
    obj->figure.plane.material.em_strenght = d->material.em_strenght;
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
    obj->figure.cylinder.material.color = d->material.color;
    obj->figure.cylinder.material.em_color = d->material.em_color;
    obj->figure.cylinder.material.em_strenght = d->material.em_strenght;
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
    obj->figure.cone.material.color = d->material.color;
    obj->figure.cone.material.em_color = d->material.em_color;
    obj->figure.cone.material.em_strenght = d->material.em_strenght;
	return (obj);
}
