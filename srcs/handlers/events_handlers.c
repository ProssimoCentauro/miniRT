/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:20:44 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/17 12:28:43 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (key == 97)
	{
		supersampler(r);
	}
	return (0);
}

int	mouse_handler(int button, int x, int y, t_renderer *r)
{
	if (button == 1)
	{
		printf("Click sinistro a (%d, %d)\n", x, y);
		r->scene->selected_obj = get_object_from_pixel(r, x, y);
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
