/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:49:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/08 12:22:43 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	start_hooks(t_renderer *renderer)
{
	mlx_key_hook(renderer->mlx->window, events_handler, renderer);
	mlx_hook(renderer->mlx->window, 17, 0, exit_handler, renderer);
}

int	main(int ac, char **av)
{
	t_renderer	*renderer;

	check_args(ac, av[1]);
	renderer = init_renderer(av[1]);
	check_file(renderer);
    calculate_up_left_and_steps(renderer);
	generate_rays(renderer);
	mlx_put_image_to_window(renderer->mlx->mlx_instance, renderer->mlx->window,
		renderer->mlx->image.img, 0, 0);
	start_hooks(renderer);
	mlx_loop(renderer->mlx->mlx_instance);
	return (0);
}
