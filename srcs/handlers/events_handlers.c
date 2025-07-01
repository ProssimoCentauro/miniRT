/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:20:44 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/30 21:20:45 by rtodaro          ###   ########.fr       */
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
	if (key == 65307)
		exit_handler(r);
	return (0);
}
