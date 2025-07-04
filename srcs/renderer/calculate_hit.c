/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:17:03 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/04 15:38:25 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb calculate_hit(t_scene *scene, t_ray *ray)
{
	t_object	*now;
	t_hit		hit_info;

	hit_info.dist = INFINITY;
	now = scene->objs;
	while (now != NULL)
	{
		if (now->type == SPHERE)
			check_collision_sphere((t_sphere *)&now->figure, ray, &hit_info);
		else if (now->type == PLANE)
			check_collision_plane((t_plane *)&now->figure, ray, &hit_info);
		else if (now->type == CYLINDER)
			check_collision_cylinder((t_cylinder *)&now->figure, ray, &hit_info);
		else if (now->type == CONE)
			check_collision_cone((t_cone *)&now->figure, ray, &hit_info);
		else
			assert(false);
		now = now->next;
	}
	if (hit_info.dist != INFINITY)
		return apply_lighting(scene, &hit_info);
	return (t_rgb){{0, 0, 0, 100}};
}


/*
// alla fine voglio che mi restituisca un t_hit
t_rgb	calculate_hit(t_scene *scene, t_ray *ray)
{
	t_object	*now;
    t_hit       hit_info;

	hit_info.dist = INFINITY;
	now = scene->objs;
	while (now != NULL)
	{
		if (now->type == SPHERE)
			check_collision_sphere((t_sphere *)&now->figure, ray, &hit_info);
		else if (now->type == PLANE)
		    check_collision_plane((t_plane *)&now->figure, ray, &hit_info);
		else if (now->type == CYLINDER)
		    check_collision_cylinder((t_cylinder *)&now->figure, ray, &hit_info);
		else if (now->type == CONE)
		    check_collision_cone((t_cone *)&now->figure, ray,   &hit_info);
		// else if (now->type == TRIANGLE)
		//     check_collision_triangle((t_tri *)&now->figure, ray, &hit_info);
		else
		    assert(false);
		now = now->next;
	}
    if (hit_info.dist != INFINITY)
        return (hit_info.rgb);
    return ((t_rgb){{0,0,0,100}});
}*/

#define MAX_RAY_BOUNCE 1

// t_rgb	follow_ray(t_scene *scene, t_ray *ray)
// {
// 	t_vector total_ligth;
// 	t_vector ray_color;
// 	t_hit hit_info;
// 	uint32_t i;

// 	total_ligth = (t_vector){0, 0, 0}; // start with 0 ligth
// 	ray_color = (t_vector){1, 1, 1};   // starts as pure white
// 	i = 0;

// 	while (i <= MAX_RAY_BOUNCE)
// 	{
//         hit_info = calculate_hit(scene, ray);
//         if (hit_info.dist == INFINITY)
//             break;
//         ray->coord = hit_info.point;
//         ray->direction = hit_info.normal;

        

        
// 		++i;
// 	}
// }
