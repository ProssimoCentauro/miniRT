/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_from_pixel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:28:46 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/08 12:35:31 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* takes a pixel and return the object if there is an object, NULL otherwise*/
t_object	*get_object_from_pixel(t_renderer *r, int32_t x, int32_t y)
{
	t_ray ray;

	if (x < 0 || x > r->mlx->width || y < 0 || y > r->mlx->height)
		return (NULL);
	ray.direction = vector_add(r->scene->cam->vp_up_left,
			vector_scale(r->scene->cam->py_step, y));
	ray.direction = vector_add(ray.direction,
			vector_scale(r->scene->cam->px_step, x));
	ray.direction = vector_normalize(vector_sub(ray.direction,
				r->scene->cam->coord));
	fill_hit_info_ray(r->scene, &ray);
	if (ray.hit.dist != INFINITY)
		return (ray.hit.obj);
	else
		return (NULL);
}
