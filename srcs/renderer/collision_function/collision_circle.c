/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:29:38 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/04 14:37:20 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_collision_circle(t_circle *circle, t_ray *ray, t_hit *hit, double *dist)
{
	t_vector	po;
	t_vector	p;
	double		denom;
	double		t;

	denom = vector_dot(circle->normal, ray->direction);
	if (fabs(denom) < EPSILON)
		return (false);
	po = vector_sub(circle->coord, ray->coord);
	t = vector_dot(circle->normal, po) / denom;
	if (t < EPSILON || t > *dist)
		return (false);
	p = vector_add(ray->coord, vector_scale(ray->direction, t));
	if (vector_lenght_squared(vector_sub(p,
				circle->coord)) > circle->radius_squared)
		return (false);
    *dist = t;
    hit->did_hit = true;
	hit->point = p;
	hit->normal = circle->normal;
	if (vector_dot(circle->normal, ray->direction) > 0)
		hit->normal = vector_invert(hit->normal);
	return (true);
}
