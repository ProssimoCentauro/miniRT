/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:34:52 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/04 15:15:08 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_collision_cone(t_cone *cone, t_ray *ray, t_hit *hit, double *dist)
{
	t_vector	oc;
	t_equation	eq;
	t_vector	p;
	double		cos2;
	double		h;
	double		A;
	double		B;
	double		C;
	double		D;
	double		E;
	t_circle	base;

	cos2 = pow(cos(cone->angle), 2);
	/* for the base*/
	base.coord = vector_add(cone->coord, vector_scale(cone->normal,
				-cone->height));
	base.normal = vector_invert(cone->normal);
	base.radius_squared = pow(cone->height * tan(cone->angle), 2);
	if (check_collision_circle(&base, ray, hit, dist))
	{
		hit->material = cone->material;
	}
	/*           */
	oc = vector_sub(ray->coord, cone->coord);
	A = vector_dot(oc, cone->normal);
	B = vector_dot(ray->direction, cone->normal);
	C = vector_lenght_squared(oc);
	D = vector_dot(oc, ray->direction);
	E = vector_lenght_squared(ray->direction);
	eq.a = B * B - E * cos2;
	eq.b = 2 * A * B - 2 * D * cos2;
	eq.c = A * A - C * cos2;
	if (!equation_solve(&eq) || (eq.t <= 0 || eq.t > *dist))
		return ;
	p = vector_add(ray->coord, vector_scale(ray->direction, eq.t));
	h = -vector_dot(vector_sub(p, cone->coord), cone->normal);
	if (h < 0 || h > cone->height)
	{
		return ;
	}
    *dist = eq.t;
    hit->did_hit = true;
	hit->point = p;
	hit->material = cone->material;
	// Normale al cono (corpo) scritto da chat da ricontrollare
	t_vector v = vector_sub(p, cone->coord);
	t_vector axis_component = vector_scale(cone->normal, vector_dot(v, cone->normal));
	t_vector radial_component = vector_sub(v, axis_component);
	t_vector n = vector_sub(radial_component, vector_scale(cone->normal, tan(cone->angle)));
    hit->normal = n;
}
