/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_up_left_and_steps.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:27:33 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/18 11:29:43 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calculate_up_left_and_steps(t_renderer *r)
{
	double		vp_height;
	double		vp_width;
	t_vector	camera_dir;
	t_vector	camera_right;
	t_vector	camera_up;

	vp_height = 2.0f * tan((r->scene->cam->fov * 0.5f) * PI / 180.0f);
	vp_width = vp_height * ((double)r->mlx->width / r->mlx->height);
	camera_dir = vector_normalize((r->scene->cam->orientation));
	camera_right = vector_normalize(vector_cross((t_vector){0, 1, 0},
				camera_dir));
	camera_up = vector_normalize(vector_cross(camera_dir, camera_right));
	r->scene->cam->px_step = vector_scale(camera_right, vp_width
			/ r->mlx->width);
	r->scene->cam->py_step = vector_scale(camera_up, -vp_height
			/ r->mlx->height);
	r->scene->cam->vp_up_left = vector_add4((r->scene->cam->coord),
			vector_scale(camera_dir, FOCAL_LENGTH), vector_scale(camera_right,
				-vp_width * 0.5f + 0.5f * (vp_width / r->mlx->width)),
			vector_scale(camera_up, vp_height * 0.5f - 0.5f * (vp_height
					/ r->mlx->height)));
	r->scene->cam->orientation = camera_dir;
	r->scene->cam->up = camera_up;
	r->scene->cam->right = camera_right;
}
