/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hit_info_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:17:03 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/15 15:39:13 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* per ora passo nei check_collision il campo stesso del ray, poi sarà
	poi da modificare per passare solo ray */
void	fill_hit_info_ray(t_scene *scene, t_ray *ray)
{
	t_object	*now;

	now = scene->objs;
	ray->hit.dist = INFINITY;
	while (now != NULL)
	{
		if (now->type == SPHERE)
			check_collision_sphere(now, ray, &ray->hit);
		else if (now->type == PLANE)
			check_collision_plane(now, ray, &ray->hit);
		else if (now->type == CYLINDER)
			check_collision_cylinder(now, ray, &ray->hit);
		else if (now->type == CONE)
			check_collision_cone(now, ray, &ray->hit);
		now = now->next;
	}
}
