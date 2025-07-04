/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:31:10 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/04 15:16:17 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_collision_bottom_top(t_cylinder *cylinder, t_ray *ray,
		t_hit *hit, double *dist)
{
	t_circle	base;

	base.coord = vector_sub(cylinder->coord, vector_scale(cylinder->normal,
				cylinder->height / 2));
	base.normal = cylinder->normal;
	base.radius_squared = pow((cylinder->diameter / 2), 2);
	if (check_collision_circle(&base, ray, hit, dist) == true)
	{
		hit->material = cylinder->material;
	}
	base.coord = vector_add(cylinder->coord, vector_scale(cylinder->normal,
				cylinder->height / 2));
	if (check_collision_circle(&base, ray, hit, dist) == true)
	{
		hit->material = cylinder->material;
	}
}

static void	get_projection(t_cylinder *cylinder, t_ray *ray,
		t_vector *d_project, t_vector *oc_project)
{
	t_vector	oc;

	oc = vector_sub(ray->coord, cylinder->coord);
	*d_project = vector_sub(ray->direction, vector_scale(cylinder->normal,
				vector_dot(ray->direction, cylinder->normal)));
	*oc_project = vector_sub(oc, vector_scale(cylinder->normal, vector_dot(oc,
					cylinder->normal)));
}

/* IMPORTANTE: cambiare la struttura per mettere r^2 e cambiare 
l'offset del punto coord su una delle due basi */
void	check_collision_cylinder(t_cylinder *cylinder, t_ray *ray,
		t_hit *hit, double *dist)
{
	t_vector	d_project;
	t_vector	oc_project;
	t_vector	p;
	t_equation	eq;

	check_collision_bottom_top(cylinder, ray, hit, dist);
	get_projection(cylinder, ray, &d_project, &oc_project);
	eq.a = vector_lenght_squared(d_project);
	eq.b = 2.0 * (vector_dot(oc_project, d_project));
	eq.c = vector_lenght_squared(oc_project) - pow((cylinder->diameter / 2), 2);
	if (!equation_solve(&eq) || (eq.t <= 0 || eq.t > *dist))
		return ;
	p = vector_add(ray->coord, vector_scale(ray->direction, eq.t));
	if (fabs(vector_dot(vector_sub(p, cylinder->coord),
				cylinder->normal)) > cylinder->height / 2)
	{
		return ;
	}
	*dist = eq.t;
    hit->did_hit = true;
	hit->point = p;
	hit->material = cylinder->material;
    
	// Calcolo della normale alla superficie laterale del cilindro
	t_vector v = vector_sub(p, cylinder->coord);
	t_vector proj = vector_scale(cylinder->normal, vector_dot(v, cylinder->normal));
	t_vector n = vector_sub(v, proj);
	hit->normal = vector_normalize(n);

	// Inverti la normale se è rivolta nella direzione del raggio
	if (vector_dot(ray->direction, hit->normal) > 0)
		hit->normal = vector_invert(hit->normal);
}
