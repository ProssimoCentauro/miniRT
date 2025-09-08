/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:18:33 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/08 12:26:00 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	color_pixel(t_renderer *r, t_ray *ray, int32_t x, int32_t y)
{
	t_rgb color;

	fill_hit_info_ray(r->scene, ray);
	if (ray->hit.dist != INFINITY)
		color = apply_lighting(r->scene, &ray->hit);
	else
		color.rgb = 0;
	*(unsigned int *)(r->mlx->image.addr + y * r->mlx->image.line_length + x
			* (r->mlx->image.bits_per_pixel >> 3)) = color.rgb;
}