/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:30 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/04 14:03:11 by ibrunial         ###   ########.fr       */
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

t_ambient	*create_ambient(t_object_data *d)
{
	t_ambient	*amb;

	amb = ft_calloc(1, sizeof(t_ambient));
	if (!amb)
		return (NULL);
	amb->type = A_LIGHT;
	amb->ratio = d->ratio;
	amb->color = d->color;
	return (amb);
}
