/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:22:15 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/03 21:32:56 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_image(t_mlx *mlx, t_image *image)
{
	image->img = mlx_new_image(mlx->mlx_instance, mlx->width, mlx->height);
	image->addr = mlx_get_data_addr(
			image->img,
			&(image)->bits_per_pixel,
			&(image)->line_length,
			&(image)->endian);
}

void	init_mlx(t_mlx	*mlx)
{
	mlx->mlx_instance = mlx_init();
	mlx_get_screen_size(mlx->mlx_instance, &(mlx)->width, &(mlx)->height);
    // alla fine rimodificherò per mettere la metà ma 
    // per i test mi servono dimensioni fisse
	mlx->width = 1280;
	mlx->height = 720;
	mlx->window = mlx_new_window(mlx->mlx_instance,
			mlx->width, mlx->height, "miniRT!");
	init_image(mlx, &(mlx)->image);
}
