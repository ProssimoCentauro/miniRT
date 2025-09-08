/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:17:03 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/08 12:26:10 by ibrunial         ###   ########.fr       */
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
			check_collision_sphere((t_sphere *)&now->figure, ray, &ray->hit);
		else if (now->type == PLANE)
			check_collision_plane((t_plane *)&now->figure, ray, &ray->hit);
		else if (now->type == CYLINDER)
			check_collision_cylinder((t_cylinder *)&now->figure, ray,
				&ray->hit);
		else if (now->type == CONE)
			check_collision_cone((t_cone *)&now->figure, ray, &ray->hit);
		now = now->next;
	}
}
