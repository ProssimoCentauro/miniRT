/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:54:35 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/30 20:11:55 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return;
	if (mlx->image.img)
		mlx_destroy_image(mlx->mlx_instance, mlx->image.img);
	if (mlx->window)
		mlx_destroy_window(mlx->mlx_instance, mlx->window);
	if (mlx->mlx_instance)
	{
		mlx_destroy_display(mlx->mlx_instance);
		free(mlx->mlx_instance);
	}
	free(mlx);
}

void	free_scene(t_scene *scene)
{
	t_object	*tmp_obj;
	t_light		*tmp_light;

	free(scene->cam);
	free(scene->amb);
	while (scene->lights)
	{
		tmp_light = scene->lights;
		scene->lights = scene->lights->next;
		free(tmp_light);
	}
	while (scene->objs)
	{
		tmp_obj = scene->objs;
		scene->objs = scene->objs->next;
		free(tmp_obj);
	}
	free(scene);
}

void	free_data(t_data *data)
{
	free(data);
}

void	free_renderer(t_renderer *r)
{
	free_mlx(r->mlx);
	free_scene(r->scene);
	free_data(r->data);
	free(r);
}

void	free_mat(char **mat)
{
	size_t	i;

	i = count_lines(mat);
	while (*mat)
	{
		free(*mat);
		mat++;
	}
	free(mat - i);
	mat = NULL;
}
