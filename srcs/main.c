/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:49:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/05 09:19:42 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	start_hooks(t_renderer *renderer)
{
	mlx_key_hook(renderer->mlx->window, events_handler, renderer);
	mlx_hook(renderer->mlx->window, 17, 0, exit_handler, renderer);
}

int general_loop(void *param)
{
    t_renderer *renderer = (t_renderer *)param;
    static int i = 0;
    generate_rays(renderer, i);
	mlx_put_image_to_window(renderer->mlx->mlx_instance, renderer->mlx->window,
		renderer->mlx->image.img, 0, 0);
    printf("\r\033[K%d\n", i);
    fflush(stdout);
    if (i == 250)
        sleep(7349);
    ++i;
    return (0);
}

int	main(int ac, char **av)
{
	t_renderer	*renderer;

	check_args(ac, av[1]);
	renderer = init_renderer(av[1]);
	check_file(renderer);
	start_hooks(renderer);
    mlx_loop_hook(renderer->mlx->mlx_instance, general_loop, (void *)renderer);
	mlx_loop(renderer->mlx->mlx_instance);
	return (0);
}
