#include "minirt.h"

void	free_mlx(t_mlx *mlx)
{
	free(mlx);
}

void	free_scene(t_scene *scene)
{
	t_object	*tmp_obj;
	t_light		*tmp_light;

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
