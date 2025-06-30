/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:57:32 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/30 18:58:55 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_data(t_data *data, char *line)
{
	data->file = line;
	data->cameras = 0;
}

t_renderer	*init_renderer(char *line)
{
	t_renderer	*r;

	r = ft_calloc(1, sizeof(t_renderer));
	r->data = ft_calloc(1, sizeof(t_data));
	r->mlx = ft_calloc(1, sizeof(t_mlx));
	r->scene = ft_calloc(1, sizeof(t_scene));
	
	init_data(r->data, line);
	init_mlx(r->mlx);
	return (r);
}
