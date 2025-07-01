/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:22:15 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/01 15:58:53 by rtodaro          ###   ########.fr       */
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
	mlx->width = mlx->width / 2;
	mlx->height = mlx->height / 2;
	mlx->window = mlx_new_window(mlx->mlx_instance, mlx->width, mlx->height, "miniRT!");
	//mlx->width = 500;
	//mlx->height = 500;
	init_image(mlx, &(mlx)->image);
}
