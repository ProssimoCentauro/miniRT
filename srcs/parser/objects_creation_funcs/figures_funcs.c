#include "minirt.h"

t_object *create_sphere(t_object_data *d)
{
	t_object *obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		return NULL;
	obj->type = SPHERE;
	obj->figure.sphere.coord = d->coord;
	obj->figure.sphere.diameter = d->diameter;
	obj->figure.sphere.rgb = d->rgb;
	return obj;
}

t_object *create_plane(t_object_data *d)
{
	t_object *obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		return NULL;
	obj->type = PLANE;
	obj->figure.plane.coord = d->coord;
	obj->figure.plane.normal = d->normal;
	obj->figure.plane.rgb = d->rgb;
	return obj;
}

t_object *create_cylinder(t_object_data *d)
{
	t_object *obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		return NULL;
	obj->type = CYLINDER;
	obj->figure.cylinder.coord = d->coord;
	obj->figure.cylinder.normal = d->normal;
	obj->figure.cylinder.diameter = d->diameter;
	obj->figure.cylinder.height = d->height;
	obj->figure.cylinder.rgb = d->rgb;
	return obj;
}
