/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:17:03 by ibrunial          #+#    #+#             */
/*   Updated: 2025/07/02 20:10:41 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief take a t_sphere pointer, a t_ray pointer and a t_hit pointer.
 * fill the t_hit pointer if the ray hit the sphere closer then the distance
 * stored in t_hit
 * 
 * @cond to verify if a point is in the surface of a sphere we check this condition:
 * || P - C ||^2 = r^2 (P and C are position vector (point). P is the point 
 * under consideration, C is the cernter of the sphere. r^2 is the radius of the sphere)
 * in other worlds we siply check if the distancec between the point and the center of
 * the sphere is equeal to the radius.
 * now we can sobsitute P with the equation of the ray: R(t) = O + Dt
 * O is the origin of the ray and D is the direction so now we have:
 * || (O + Dt) - C ||^2 = r^2 we solve for t and we get:
 * || O - C + Dt ||^2 = r^2
 * || oc + Dt ||^2 = r^2
 * (D ⋅ D)t^2 + 2*(oc ⋅ D)t + (oc ⋅ oc - r^2) ( ' ⋅ ' is dot product)
 * oc is the distance between the center of the sphere C and the origin of the ray O
 * now D is normalized so it doesn't appear on the function (distance of a versor is 1)
 * 
 * NOTE: we reuse discriminant variable after the check of positivity
 */
void	check_collision_sphere(t_sphere *sphere, t_ray *ray, t_hit *hit_info)
{
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
    if (t <= 0 || t > hit_info->dist)
    {
        return;
    }
	hit_info->dist = t;
	hit_info->point = vector_add(ray->coord, vector_scale(ray->direction, t));
	hit_info->normal = vector_normalize(vector_sub(hit_info->point,
				sphere->coord));
	hit_info->rgb = sphere->rgb;
    hit_info->obj = (t_figures *)sphere;
}

/**
 * @cond to verify if where a point hit the plane we check this condition:
 * (E - P) ⋅ n = 0 (E is the point under consideration, P is a point on the plane
 * and n is the normal of the plane)
 * now we can sobsitute E with the equation of the ray: R(t) = O + Dt
 * ((O + Dt) - P) ⋅ n = 0
 * (op + Dt) ⋅ n = 0
 * (n ⋅ op) + (n ⋅ Dt) = 0
 * (n ⋅ op) + t(n ⋅ D) = 0
 * t = -(n ⋅ op) / (n ⋅ D)
 * op is the difference between O and P
 * before 
 */
void check_collision_plane(t_plane *plane, t_ray *ray, t_hit *hit_info)
{
    t_vector po;
    double denom;
    double t;

    denom = vector_dot(plane->normal, ray->direction);
    if (fabs(denom) < EPSILON)
        return ;

    po = vector_sub(plane->coord, ray->coord);
    t = -vector_dot(plane->normal, po) / denom;
    if (t < EPSILON || t > hit_info->dist)
        return ;
    hit_info->dist = t;
    hit_info->point = vector_add(ray->coord, vector_scale(ray->direction, t));
    hit_info->normal = plane->normal;
	hit_info->rgb = plane->rgb;
    hit_info->obj = (t_figures *)plane;
}

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
    if (hit_info.dist != INFINITY)
        return (hit_info.rgb);
    return ((t_rgb){0,0,0});
}

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
