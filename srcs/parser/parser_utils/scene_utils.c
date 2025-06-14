#include "minirt.h"

void	add_object(t_scene *scene, t_object *new_obj)
{
	t_object	*tmp;

	if (!scene || !new_obj)
		return ;
	new_obj->next = NULL;
	if (!scene->objs)
	{
		scene->objs = new_obj;
		return ;
	}
	tmp = scene->objs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_obj;
}

void	add_light(t_scene *scene, t_light *new_light)
{
	t_light	*tmp;

	if (!scene || !new_light)
		return ;
	new_light->next = NULL;
	if (!scene->lights)
	{
		scene->lights = new_light;
		return ;
	}
	tmp = scene->lights;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_light;
}



