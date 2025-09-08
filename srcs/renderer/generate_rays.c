/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:01:23 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/08 12:27:44 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	generate_rays(t_renderer *r)
{
	t_vector	row_start;
	t_ray		ray;
	int32_t		y;
	int32_t		x;

	y = 0;
	while (y < r->mlx->height)
	{
		x = 0;
		row_start = vector_add(r->scene->cam->vp_up_left,
				vector_scale(r->scene->cam->py_step, y));
		while (x < r->mlx->width)
		{
			ray.direction = vector_add(row_start,
					vector_scale(r->scene->cam->px_step, x));
			ray.direction = vector_normalize(vector_sub(ray.direction,
						r->scene->cam->coord));
			ray.coord = r->scene->cam->coord; /* forse da togliere */
			color_pixel(r, &ray, x, y);
			++x;
		}
		++y;
	}
}

