/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:22:15 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/30 21:22:35 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_image(void	*mlx, t_image *image)
{
	image->img = mlx_new_image(mlx, 500, 500);
	image->addr = mlx_get_data_addr(
			image->img,
			&(image)->bits_per_pixel,
			&(image)->line_length,
			&(image)->endian);
}

void	init_mlx(t_mlx	*mlx)
{
	mlx->mlx_instance = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_instance, 500, 500, "miniRT!");
	mlx->width = 500;
	mlx->height = 500;
	init_image(mlx->mlx_instance, &(mlx)->image);
}
