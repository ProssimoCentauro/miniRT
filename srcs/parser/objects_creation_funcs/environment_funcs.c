/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:30 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/16 19:51:33 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*create_camera(t_object_data *d)
{
	t_camera	*cam;

	cam = ft_calloc(1, sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->type = CAMERA;
	cam->coord = d->coord;
	cam->orientation = d->normal;
	cam->fov = d->fov;
	return (cam);
}

t_light	*create_light(t_object_data *d)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (NULL);
	light->coord = d->coord;
	light->brightness = d->brightness;
	light->rgb = d->rgb;
	return (light);
}

t_ambient	*create_ambient(t_object_data *d)
{
	t_ambient	*amb;

	amb = ft_calloc(1, sizeof(t_ambient));
	if (!amb)
		return (NULL);
	amb->type = A_LIGHT;
	amb->ratio = d->ratio;
	amb->rgb = d->rgb;
	return (amb);
}
