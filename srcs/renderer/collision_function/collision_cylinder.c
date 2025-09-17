/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:31:10 by ibrunial          #+#    #+#             */
/*   Updated: 2025/09/15 15:39:56 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"


/* ************************************************************************** */
/*                                MODIFICHE                                   */
/*                                                                            */
/* - Aggiunto calcolo della normale per il lato del cilindro:                 */
/*     -> La normale ora è calcolata proiettando il punto d'impatto sul      */
/*        asse del cilindro e sottraendo il vettore proiettato dal punto     */
/*        per ottenere la direzione perpendicolare.                          */
/*                                                                            */
/* - Refactoring di check_collision_bottom_top:                              */
/*     -> Utilizzo di una variabile temporanea (temp_hit) per evitare        */
/*        di sovrascrivere hit_info se l'intersezione non è più vicina.      */
/*     -> Migliore gestione dell'intersezione con le due basi.               */
/*                                                                            */
/* - get_projection reso più leggibile:                                      */
/*     -> Nomi coerenti (d_proj, oc_proj) e codice più compatto.             */
/*                                                                            */
/* - Migliorata stabilità della logica di check_collision_cylinder:          */
/*     -> Verifica della distanza dell'intersezione solo se effettivamente   */
/*        più vicina di quella già trovata.                                  */
/*     -> Controllo più preciso della posizione lungo l'asse del cilindro.   */
/*                                                                            */
/* - Rimossi vecchi commenti inutili e parti incomplete (es. normal mancanti).*/
/*                                                                            */
/* ************************************************************************** */

static void	check_collision_bottom_top(t_object *obj, t_ray *ray, t_hit *hit_info)
{
    t_cylinder *cylinder = (t_cylinder *)&obj->figure;
	t_circle	base;
	t_hit		temp_hit;

	temp_hit = *hit_info;

	base.coord = vector_sub(cylinder->coord, vector_scale(cylinder->normal, cylinder->height / 2));
	base.normal = cylinder->normal;
	base.radius_squared = pow((cylinder->diameter / 2), 2);
	if (check_collision_circle(&base, ray, &temp_hit))
	{
		*hit_info = temp_hit;
		hit_info->rgb = cylinder->rgb;
		hit_info->obj = obj;
	}

	temp_hit = *hit_info;
	base.coord = vector_add(cylinder->coord, vector_scale(cylinder->normal, cylinder->height / 2));
	base.normal = vector_invert(cylinder->normal);
	if (check_collision_circle(&base, ray, &temp_hit))
	{
		*hit_info = temp_hit;
		hit_info->rgb = cylinder->rgb;
		hit_info->obj = obj;
	}
}

static void	get_projection(t_cylinder *cylinder, t_ray *ray, t_vector *d_proj, t_vector *oc_proj)
{
	t_vector	oc = vector_sub(ray->coord, cylinder->coord);

	*d_proj = vector_sub(ray->direction,
			vector_scale(cylinder->normal, vector_dot(ray->direction, cylinder->normal)));
	*oc_proj = vector_sub(oc,
			vector_scale(cylinder->normal, vector_dot(oc, cylinder->normal)));
}

void	check_collision_cylinder(t_object *obj, t_ray *ray, t_hit *hit_info)
{
    t_cylinder *cylinder = (t_cylinder *)&obj->figure;
	t_vector	d_proj;
	t_vector	oc_proj;
	t_vector	p;
	t_equation	eq;

	check_collision_bottom_top(obj, ray, hit_info);
	get_projection(cylinder, ray, &d_proj, &oc_proj);

	eq.a = vector_length_squared(d_proj);
	eq.b = 2 * vector_dot(d_proj, oc_proj);
	eq.c = vector_length_squared(oc_proj) - pow(cylinder->diameter / 2, 2);

	if (!equation_solve(&eq) || eq.t <= 0 || eq.t > hit_info->dist)
		return ;

	p = vector_add(ray->coord, vector_scale(ray->direction, eq.t));

	if (fabs(vector_dot(vector_sub(p, cylinder->coord), cylinder->normal)) > cylinder->height / 2)
		return ;

	hit_info->dist = eq.t;
	hit_info->point = p;
	hit_info->rgb = cylinder->rgb;

	// Calcolo normale lato
	t_vector	pc = vector_sub(p, cylinder->coord);
	t_vector	axis_proj = vector_scale(cylinder->normal, vector_dot(pc, cylinder->normal));
	hit_info->normal = vector_normalize(vector_sub(pc, axis_proj));

	hit_info->obj = obj;
}


/*
#include "minirt.h"

static void	check_collision_bottom_top(t_cylinder *cylinder, t_ray *ray,
		t_hit *hit_info)
{
	t_circle	base;

	base.coord = vector_sub(cylinder->coord, vector_scale(cylinder->normal,
				cylinder->height / 2));
	base.normal = cylinder->normal;
	base.radius_squared = pow((cylinder->diameter / 2), 2);
	if (check_collision_circle(&base, ray, hit_info) == true)
	{
		hit_info->obj = (t_figures *)cylinder;
		hit_info->rgb = cylinder->rgb;
	}
	base.coord = vector_add(cylinder->coord, vector_scale(cylinder->normal,
				cylinder->height / 2));
	if (check_collision_circle(&base, ray, hit_info) == true)
	{
		hit_info->obj = (t_figures *)cylinder;
		hit_info->rgb = cylinder->rgb;
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

// IMPORTANTE: cambiare la struttura per mettere r^2 e cambiare 
//l'offset del punto coord su una delle due basi
void	check_collision_cylinder(t_cylinder *cylinder, t_ray *ray,
		t_hit *hit_info)
{
	t_vector	d_project;
	t_vector	oc_project;
	t_vector	p;
	t_equation	eq;

	check_collision_bottom_top(cylinder, ray, hit_info);
	get_projection(cylinder, ray, &d_project, &oc_project);
	eq.a = vector_length_squared(d_project);
	eq.b = 2.0 * (vector_dot(oc_project, d_project));
	eq.c = vector_length_squared(oc_project) - pow((cylinder->diameter / 2), 2);
	if (!equation_solve(&eq) || (eq.t <= 0 || eq.t > hit_info->dist))
		return ;
	p = vector_add(ray->coord, vector_scale(ray->direction, eq.t));
	if (fabs(vector_dot(vector_sub(p, cylinder->coord),
				cylinder->normal)) > cylinder->height / 2)
	{
		return ;
	}
	hit_info->dist = eq.t;
	hit_info->point = p;
	hit_info->rgb = cylinder->rgb;
	// hit_info->normal = ??
	hit_info->obj = (t_figures *)cylinder;
}*/
