/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:57:32 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/16 19:57:33 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_renderer	*init_renderer(char *line)
{
	t_renderer	*r;

	r = ft_calloc(1, sizeof(t_renderer));
	r->data = ft_calloc(1, sizeof(t_data));
	r->mlx = ft_calloc(1, sizeof(t_mlx));
	r->scene = ft_calloc(1, sizeof(t_scene));
	r->data->file = line;
	r->data->cameras = 0;
	return (r);
}
