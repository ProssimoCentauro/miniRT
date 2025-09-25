/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:24:42 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/15 15:41:57 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief take a t_sphere pointer, a t_ray pointer and a t_hit pointer.
 * fill the t_hit pointer if the ray hit the sphere closer then the distance
 * stored in t_hit
 *
 * @cond to verify if a point is on surface of a sphere we check this condition:
 * || P - C ||^2 = r^2 (P and C are position vector (point). P is the point
 * under consideration, C is the cernter of the sphere. r^2 is the radius of
 * the sphere) in other worlds we siply check if the distance between
 * the point and the center of the sphere is equeal to the radius.
 * now we can sobsitute P with the equation of the ray: R(t) = O + Dt
 * O is the origin of the ray and D is the direction so now we have:
 * || (O + Dt) - C ||^2 = r^2 we solve for t and we get:
 * || O - C + Dt ||^2 = r^2
 * || oc + Dt ||^2 = r^2
 * (D ⋅ D)t^2 + 2*(oc ⋅ D)t + (oc ⋅ oc - r^2) ( ' ⋅ ' is dot product)
 * oc is the distance between the center of the sphere C
 * and the origin of the ray O
 * now D is normalized so it doesn't appear on the function
 * (dot_product of a versor is 1)
 *
 * NOTE: we reuse discriminant variable after the check of positivity
 */
void	check_collision_sphere(t_object *obj, t_ray *ray, t_hit *hit)
{
    t_sphere *sphere = (t_sphere *)&obj->figure;
	t_vector	oc;
	double		b;
	double		c;
	double		discriminant;
	double		t;

	oc = vector_sub(ray->coord, sphere->coord);
	b = 2.0 * vector_dot(oc, ray->direction);
	c = vector_dot(oc, oc) - pow((sphere->diameter / 2.0), 2);
	discriminant = b * b - 4 * c;
	if (discriminant < 0)
		return ;
	discriminant = sqrt(discriminant);
	t = (-b - discriminant) / 2.0;
	if (t <= 0)
		t = (-b + discriminant) / 2.0;
	if (t <= 0 || t > hit->dist)
	{
		return ;
	}
	hit->dist = t;
	hit->point = vector_add(ray->coord, vector_scale(ray->direction, t));
	hit->normal = vector_normalize(vector_sub(hit->point, sphere->coord));
	hit->rgb = sphere->rgb;
	hit->obj = obj;
}
