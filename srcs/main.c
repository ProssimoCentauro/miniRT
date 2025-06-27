/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:49:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/27 14:17:47 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void init_mlx(t_mlx *mlx)
{
    mlx->mlx_instance = mlx_init();
    mlx->window = mlx_new_window(mlx->mlx_instance, mlx->width, mlx->height, WINDOW_NAME);
    mlx->image.img = mlx_new_image(mlx->mlx_instance, mlx->width, mlx->height);
    mlx->image.addr = (char *)mlx_get_data_addr(mlx->image.img, &mlx->image.bits_per_pixel, &mlx->image.line_length, &mlx->image.endian);
}


int	main(int ac, char **av)
{
	t_renderer	*renderer;

	check_args(ac, av[1]);
	renderer = init_renderer(av[1]);
	check_file(renderer);

    /* TEMP */
    renderer->mlx->height = HEIGHT;
    renderer->mlx->width = WIDTH;
    /* //// */
    
    init_mlx(renderer->mlx);
    generate_rays(renderer);
    
    mlx_put_image_to_window(renderer->mlx->mlx_instance, renderer->mlx->window, renderer->mlx->image.img, 0, 0);
    mlx_loop(renderer->mlx->mlx_instance);

    
	free_renderer(renderer);
	return (0);
}
