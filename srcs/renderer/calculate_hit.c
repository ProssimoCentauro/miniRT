/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:17:03 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/04 16:16:10 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* alla fine voglio che mi restituisca un t_hit*/
t_hit	calculate_hit(t_scene *scene, t_ray *ray)
{
	t_object	*now;
    t_hit       hit;
    double      dist;

	dist = INFINITY;
	now = scene->objs;
	while (now != NULL)
	{
		if (now->type == SPHERE)
			check_collision_sphere((t_sphere *)&now->figure, ray, &hit, &dist);
		else if (now->type == PLANE)
		    check_collision_plane((t_plane *)&now->figure, ray, &hit, &dist);
		else if (now->type == CYLINDER)
		    check_collision_cylinder((t_cylinder *)&now->figure, ray, &hit, &dist);
		else if (now->type == CONE)
		    check_collision_cone((t_cone *)&now->figure, ray, &hit, &dist);
		else
		    assert(false);
		now = now->next;
	}
    return (hit);
}

#define MAX_RAY_BOUNCE 3

t_color	follow_ray(t_scene *scene, t_ray *ray)
{
	t_color total_ligth;
	t_color ray_color;
	t_hit hit;
	uint32_t i;

	total_ligth = (t_color){0, 0, 0}; // start with 0 ligth
	ray_color = (t_color){1, 1, 1};   // starts as pure white
    
	i = 0;
	while (i <= MAX_RAY_BOUNCE)
	{
        hit = calculate_hit(scene, ray);
        if (hit.did_hit == false)
            break;
        ray->coord = hit.point;
        ray->direction = random_semisphere_direction(hit.normal);

        t_color emitted_ligth = multiply_color_scalar(hit.material.em_color, hit.material.em_strenght);
        total_ligth = add_color(total_ligth, multiply_color(emitted_ligth, ray_color));
        ray_color = multiply_color(ray_color, hit.material.color);
		++i;
	}
    
    return (total_ligth);
}
