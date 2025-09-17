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

t_rgb trace_ray(t_renderer *r, t_ray *ray)
{
    t_rgb color;

    fill_hit_info_ray(r->scene, ray);
    if (ray->hit.dist != INFINITY)
        color = apply_lighting(r->scene, &ray->hit);
    else
        memset(&color, 0, sizeof(t_rgb));
    return color;
}

static t_rgb	sample_pixel(t_renderer *r, int x, int y, t_offset o)
{
	t_ray		ray;
	t_vector	pixel_pos;
	t_rgb		color;

	pixel_pos = vector_add(r->scene->cam->vp_up_left,
			vector_scale(r->scene->cam->px_step, x + o.ox));
	pixel_pos = vector_add(pixel_pos,
			vector_scale(r->scene->cam->py_step, y + o.oy));
	ray.coord = r->scene->cam->coord;
	ray.direction = vector_normalize(vector_sub(pixel_pos, ray.coord));
	color = trace_ray(r, &ray);
	return (color);
}

static t_rgb	average_pixel_color(t_renderer *r, int x, int y, int sqrt_s)
{
	int			sx;
	int			sy;
	t_rgb		color;
	t_rgb		sample;
	t_offset	o;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	sy = 0;
	while (sy < sqrt_s)
	{
		sx = 0;
		while (sx < sqrt_s)
		{
			o.ox = (sx + 0.5) / sqrt_s;
			o.oy = (sy + 0.5) / sqrt_s;
			sample = sample_pixel(r, x, y, o);
			color = rgb_add(color, sample);
			sx++;
		}
		sy++;
	}
	color = rgb_scale(color, 1.0 / (sqrt_s * sqrt_s));
	return (color);
}

static void	put_pixel_img(t_renderer *r, int x, int y, t_rgb color)
{
	unsigned int	rgb;

	rgb = (color.r << 16) | (color.g << 8) | color.b;
	*(unsigned int *)(r->mlx->image.addr
		+ y * r->mlx->image.line_length
		+ x * (r->mlx->image.bits_per_pixel >> 3)) = rgb;
}

void	generate_rays_supersampling(t_renderer *r)
{
	int		x;
	int		y;
	int		sqrt_s;
	t_rgb	color;

	sqrt_s = 4;
	y = 0;
	while (y < r->mlx->height)
	{
		x = 0;
		while (x < r->mlx->width)
		{
			color = average_pixel_color(r, x, y, sqrt_s);
			put_pixel_img(r, x, y, color);
			x++;
		}
		y++;
	}
}

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
			ray.coord = r->scene->cam->coord; // forse da togliere //
			color_pixel(r, &ray, x, y);
			++x;
		}
		++y;
	}
}

