#include "minirt.h"

t_camera *create_camera(t_object_data *d)
{
	t_camera *cam = ft_calloc(1, sizeof(t_camera));
	if (!cam)
		return NULL;
	cam->type = CAMERA;
	cam->coord = d->coord;
	cam->orientation = d->normal;
	cam->fov = d->fov;
	return cam;
}

t_light *create_light(t_object_data *d)
{
	t_light *light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return NULL;
	light->coord = d->coord;
	light->brightness = d->brightness;
	light->rgb = d->rgb;
	return light;
}

t_ambient *create_ambient(t_object_data *d)
{
	t_ambient *amb = ft_calloc(1, sizeof(t_ambient));
	if (!amb)
		return NULL;
	amb->type = A_LIGHT;
	amb->ratio = d->ratio;
	amb->rgb = d->rgb;
	return amb;
}
