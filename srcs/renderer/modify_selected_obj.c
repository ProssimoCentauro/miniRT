/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_selected_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:28:28 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/17 12:28:29 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	modify_sphere(t_sphere *s, int key)
{
	if (key == 65362)
		s->diameter += STEP_SIZE;
	else if (key == 65364 && s->diameter > STEP_SIZE)
		s->diameter -= STEP_SIZE;
}

static void	modify_cylinder(t_cylinder *c, int key)
{
	if (key == 65362)
		c->height += STEP_SIZE;
	else if (key == 65364 && c->height > STEP_SIZE)
		c->height -= STEP_SIZE;
	else if (key == 65361)
		c->diameter -= STEP_SIZE;
	else if (key == 65363)
		c->diameter += STEP_SIZE;
}

static void	modify_cone(t_cone *c, int key)
{
	if (key == 65362)
		c->angle += ANGLE_STEP;
	else if (key == 65364 && c->angle > ANGLE_STEP)
		c->angle -= ANGLE_STEP;
	else if (key == 65361)
		c->height -= STEP_SIZE;
	else if (key == 65363)
		c->height += STEP_SIZE;
}

void	modify_selected_obj(int key, t_renderer *r)
{
	t_object	*obj;

	obj = r->scene->selected_obj;
	if (!obj)
		return ;
	if (obj->type == SPHERE)
		modify_sphere(&obj->figure.sphere, key);
	else if (obj->type == CYLINDER)
		modify_cylinder(&obj->figure.cylinder, key);
	else if (obj->type == CONE)
		modify_cone(&obj->figure.cone, key);
}
