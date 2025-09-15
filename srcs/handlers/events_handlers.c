/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:20:44 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/15 19:55:05 by rtodaro          ###   ########.fr       */
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

void	move_selected_obj(int key, t_renderer *r)
{
	t_vector	*obj_coord;

	obj_coord = get_obj_coord(r->scene->selected_obj);
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
	if (key >= 49 && key <= 54 && r->scene->selected_obj)
	{
		move_selected_obj(key, r);
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
