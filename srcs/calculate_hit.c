/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:17:03 by ibrunial          #+#    #+#             */
/*   Updated: 2025/06/27 14:17:39 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// fatto da chat da ricontrollare (sistema retta cerchio e vado a risolvere l'eq di secondo grado)
void check_collision_sphere(t_sphere *sphere, t_ray *ray)
{   
	t_vector oc = vector_sub(ray->coord, sphere->coord);

	double a = vector_dot(ray->direction, ray->direction);
	double b = 2.0 * vector_dot(oc, ray->direction);
	double c = vector_dot(oc, oc) - pow((sphere->diameter / 2.0), 2);

	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;

	double sqrt_d = sqrt(discriminant);
	double t1 = (-b - sqrt_d) / (2 * a);
	double t2 = (-b + sqrt_d) / (2 * a);
	double t;

	if (t1 > 0)
		t = t1;
	else if (t2 > 0)
		t = t2;

	// Calcolo il punto di impatto
    if (t > ray->hit->dist)
    {
        return ;
    }
	ray->hit->dist = t;
	ray->hit->point = vector_add(ray->coord, vector_scale(ray->direction, t));
	ray->hit->normal = vector_normalize(vector_sub(ray->hit->point, sphere->coord));
	ray->hit->rgb = (t_rgb){255, 0, 0}; // colore provvisorio, o da passare
}

t_rgb calculate_hit(t_scene *scene, t_ray *ray)
{
    t_object *now;
    ray->hit = (t_hit *)malloc(sizeof(t_hit));
    ray->hit->dist = INFINITY;
    
    now = scene->objs;
    while (now != NULL)
    {
        if (now->type == SPHERE)
            check_collision_sphere((t_sphere *)&now->figure, ray);
        // else if (now->type == PLANE)
        //     check_collision_plane(&now->figure, ray);
        // else if (now->type == CYLINDER)
        //     check_collision_cylindef(&now->figure, ray);
        // else if (now->type == CONE)
        //     check_collision_cone(&now->figure, ray);
        // else if (now->type == TRIANGLE)
        //     check_collision_triangle(&now->figure, ray);
        // else
        //     printf("ERRORE NON DEVE RAGGIUNGERE QUESTO PUNTO\n");
        now = now->next;
    }
    if (ray->hit->dist != INFINITY)
        return (ray->hit->rgb);
    else
        return ((t_rgb){0,0,0});
}