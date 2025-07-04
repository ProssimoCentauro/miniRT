/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:52:04 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/04 14:06:34 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_object(t_scene *scene, t_object *new_obj)
{
	t_object	*tmp;

	if (!scene || !new_obj)
		return ;
	new_obj->next = NULL;
	if (!scene->objs)
	{
		scene->objs = new_obj;
		return ;
	}
	tmp = scene->objs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_obj;
}

