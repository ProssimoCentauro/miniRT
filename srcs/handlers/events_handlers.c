/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:20:44 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/15 21:25:21 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*get_obj_coord(t_object *obj)
{
	if (!obj)
		return (NULL);
	if (obj->type == SPHERE)
		return (&obj->figure.sphere.coord);
	if (obj->type == PLANE)
		return (&obj->figure.plane.coord);
	if (obj->type == CYLINDER)
		return (&obj->figure.cylinder.coord);
	if (obj->type == CONE)
		return (&obj->figure.cone.coord);
	return (NULL);
}

t_vector *get_obj_normal(t_object *obj)
{
	if (!obj)
		return (NULL);
	if (obj->type == PLANE)
		return (&obj->figure.plane.normal);
	if (obj->type == CYLINDER)
		return (&obj->figure.cylinder.normal);
	if (obj->type == CONE)
		return (&obj->figure.cone.normal);
	return (NULL);
}


t_vector rotate_vector_axis(t_vector v, t_vector axis, double angle)
{
    t_vector res;
    double cos_t = cos(angle);
    double sin_t = sin(angle);

    axis = vector_normalize(axis); // importantissimo!

    res = vector_add(
              vector_scale(v, cos_t),
              vector_add(
                  vector_scale(vector_cross(axis, v), sin_t),
                  vector_scale(axis, vector_dot(axis, v) * (1 - cos_t))
              )
          );
    return res;
}


void	move_selected_obj(int key, t_renderer *r)
{
	t_vector	*obj_coord;
	t_vector	*obj_normal;

	obj_coord	= get_obj_coord(r->scene->selected_obj);
	obj_normal  = get_obj_normal(r->scene->selected_obj);
	if (key == 49)
		*obj_coord = vector_sub(*obj_coord, r->scene->cam->right);
	else if (key == 50)
		*obj_coord = vector_add(*obj_coord, r->scene->cam->right);
	else if (key == 51)
		*obj_coord = vector_sub(*obj_coord, r->scene->cam->up);
	else if (key == 52)
		*obj_coord = vector_add(*obj_coord, r->scene->cam->up);
	else if (key == 53)
		*obj_coord = vector_add(*obj_coord, r->scene->cam->orientation);
	else if (key == 54)
		*obj_coord = vector_sub(*obj_coord, r->scene->cam->orientation);
	else if (key == 55 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal, r->scene->cam->up, M_PI / 36);
	else if (key == 56 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal, r->scene->cam->up, M_PI / -36);
	else if (key == 57 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal, r->scene->cam->right, M_PI / -36);
	else if (key == 48 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal, r->scene->cam->right, M_PI / 36);
}

static void modify_sphere(t_sphere *s, int key)
{
	if (key == 65362)
		s->diameter += STEP_SIZE;
	else if (key == 65364 && s->diameter > STEP_SIZE)
		s->diameter -= STEP_SIZE;
}

static void modify_cylinder(t_cylinder *c, int key)
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

static void modify_cone(t_cone *c, int key)
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

void modify_selected_obj(int key, t_renderer *r)
{
	t_object *obj = r->scene->selected_obj;

	if (!obj)
		return ;
	if (obj->type == SPHERE)
		modify_sphere(&obj->figure.sphere, key);
	else if (obj->type == CYLINDER)
		modify_cylinder(&obj->figure.cylinder, key);
	else if (obj->type == CONE)
		modify_cone(&obj->figure.cone, key);
	// esempio: il piano non ha "dimensioni", quindi niente
}

int	exit_handler(t_renderer *r)
{
	free_renderer(r);
	exit(EXIT_SUCCESS);
	return (0);
}

int	events_handler(int key, t_renderer *r)
{
	printf("key: %d\n", key);
	if ((char)key == '\033')
		exit_handler(r);
	if (key >= 48 && key <= 57 && r->scene->selected_obj)
	{
		move_selected_obj(key, r);
		render_scene(r);
	}
	if (key >= 65361 && key <= 65364 && r->scene->selected_obj)
	{
		modify_selected_obj(key, r);
		render_scene(r);
	}
	return (0);
}

int mouse_handler(int button, int x, int y, t_renderer* r)
{
    if (button == 1)
	{
        printf("Click sinistro a (%d, %d)\n", x, y);
		r->scene->selected_obj = get_object_from_pixel(r, x , y);
		//change_selected_obj(r, x, y);
		if (r->scene->selected_obj)
			printf("oggetto selezionato: %d\n", r->scene->selected_obj->type);
		else
			printf("nessun oggetto selezionato\n");
	}
	else if (button == 2)
        printf("Click destro a (%d, %d)\n", x, y);
    else if (button == 4)
        printf("Scroll su a (%d, %d)\n", x, y);
    else if (button == 5)
        printf("Scroll giù a (%d, %d)\n", x, y);
    return (0);
}
