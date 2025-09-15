/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:49:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/09/15 19:53:43 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static inline void	start_hooks(t_renderer *r)
{
	mlx_key_hook(r->mlx->window, events_handler, r);
	mlx_hook(r->mlx->window, 17, 0, exit_handler, r);
	mlx_mouse_hook(r->mlx->window, mouse_handler, r);
}

void render_scene(t_renderer *r)
{
    calculate_up_left_and_steps(r);
	generate_rays(r);
	mlx_put_image_to_window(r->mlx->mlx_instance, r->mlx->window,
		r->mlx->image.img, 0, 0);
	printf(SCENE_RENDERED_MSG);
}

int	main(int ac, char **av)
{
	t_renderer	*renderer;

	check_args(ac, av[1]);
	renderer = init_renderer(av[1]);
	check_file(renderer);
	start_hooks(renderer);
	render_scene(renderer);
	mlx_loop(renderer->mlx->mlx_instance);
	return (0);
}
