/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:28:50 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/07 16:23:20 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @cond to verify if where a point hit the plane we check this condition:
 * (E - P) ⋅ n = 0 (E is the point under consideration,
		P is a point on the plane
 * and n is the normal of the plane)
 * now we can sobsitute E with the equation of the ray: R(t) = O + Dt
 * ((O + Dt) - P) ⋅ n = 0
 * ((O - P) + Dt) ⋅ n = 0       // po = P - O → O - P = -po
 * (-po + Dt) ⋅ n = 0
 * - (n ⋅ po) + t(n ⋅ D) = 0
 * t(n ⋅ D) = (n ⋅ po)
 * t = (n ⋅ po) / (n ⋅ D)
 */
void	check_collision_plane(t_plane *plane, t_ray *ray, t_hit *hit, double *dist)
{
	t_vector	po;
	double		denom;
	double		t;

	denom = vector_dot(plane->normal, ray->direction);
	if (fabs(denom) < EPSILON)
		return ;
	po = vector_sub(plane->coord, ray->coord);
	t = vector_dot(plane->normal, po) / denom;
	if (t < EPSILON || t > *dist)
		return ;
	*dist = t;
	hit->point = vector_add(ray->coord, vector_scale(ray->direction, t));
	hit->normal = plane->normal;
	if (vector_dot(plane->normal, ray->direction) > 0)
	{
		hit->normal = vector_invert(hit->normal);
	}
    hit->did_hit = true;
	hit->material = plane->material;
}
