/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:34:52 by ibrunial          #+#    #+#             */
/*   Updated: 2025/10/11 15:36:22 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	verify_base(t_help_co_coll *h, t_object *obj, t_ray *ray,
		t_hit *hit_info)
{
	const t_cone	*cone = (t_cone *)&obj->figure;
	t_circle		base;

	h->cos2 = pow(cos(cone->angle), 2);
	base.coord = vector_add(cone->coord, vector_scale(cone->normal,
				-cone->height));
	base.normal = vector_invert(cone->normal);
	base.radius_squared = pow(cone->height * tan(cone->angle), 2);
	if (check_collision_circle(&base, ray, hit_info))
	{
		hit_info->rgb = cone->rgb;
		hit_info->obj = obj;
	}
}

static bool	set_up_equation(t_help_co_coll *h, t_object *obj, t_ray *ray,
		t_hit *hit_info)
{
	const t_cone	*cone = (t_cone *)&obj->figure;
	t_equation		eq;

	h->oc = vector_sub(ray->coord, cone->coord);
	h->a = vector_dot(h->oc, cone->normal);
	h->b = vector_dot(ray->direction, cone->normal);
	h->c = vector_length_squared(h->oc);
	h->d = vector_dot(h->oc, ray->direction);
	h->e = vector_length_squared(ray->direction);
	eq.a = h->b * h->b - h->e * h->cos2;
	eq.b = 2 * h->a * h->b - 2 * h->d * h->cos2;
	eq.c = h->a * h->a - h->c * h->cos2;
	if (!equation_solve(&eq) || (eq.t <= 0 || eq.t > hit_info->dist))
		return (true);
	h->p = vector_add(ray->coord, vector_scale(ray->direction, eq.t));
	h->h = -vector_dot(vector_sub(h->p, cone->coord), cone->normal);
	if (h->h < 0 || h->h > cone->height)
		return (true);
	hit_info->dist = eq.t;
	hit_info->point = h->p;
	hit_info->rgb = cone->rgb;
	hit_info->obj = obj;
	return (false);
}

void	check_collision_cone(t_object *obj, t_ray *ray, t_hit *hit_info)
{
	const t_cone	*cone = (t_cone *)&obj->figure;
	t_help_co_coll	h;

	verify_base(&h, obj, ray, hit_info);
	if (set_up_equation(&h, obj, ray, hit_info))
		return ;
	h.v = vector_sub(h.p, cone->coord);
	h.axis_component = vector_scale(cone->normal, vector_dot(h.v,
				cone->normal));
	h.radial_component = vector_sub(h.v, h.axis_component);
	h.n = vector_sub(h.radial_component, vector_scale(cone->normal,
				tan(cone->angle)));
	hit_info->normal = h.n;
}
