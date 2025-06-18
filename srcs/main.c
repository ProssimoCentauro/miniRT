/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:49:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/18 19:49:56 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_renderer	*renderer;

	check_args(ac, av[1]);
	renderer = init_renderer(av[1]);
	check_file(renderer);
	free_renderer(renderer);
	return (0);
}
