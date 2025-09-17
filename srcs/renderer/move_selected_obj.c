#include "minirt.h"

static void	rotate_selected_obj(t_vector *obj_normal, int key, t_renderer *r)
{
	if (key == 55 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal,
				r->scene->cam->up, M_PI / 36);
	else if (key == 56 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal,
				r->scene->cam->up, M_PI / -36);
	else if (key == 57 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal,
				r->scene->cam->right, M_PI / -36);
	else if (key == 48 && obj_normal)
		*obj_normal = rotate_vector_axis(*obj_normal,
				r->scene->cam->right, M_PI / 36);
}

void	move_selected_obj(int key, t_renderer *r)
{
	t_vector	*obj_coord;
	t_vector	*obj_normal;

	obj_coord = get_obj_coord(r->scene->selected_obj);
	obj_normal = get_obj_normal(r->scene->selected_obj);
	if (key == 49)
		*obj_coord = vector_sub(*obj_coord, r->scene->cam->right);
	else if (key == 50)
		*obj_coord = vector_add(*obj_coord, r->scene->cam->right);
	else if (key == 51)
		*obj_coord = vector_sub(*obj_coord, r->scene->cam->up);
	else if (key == 52)
		*obj_coord = vector_add(*obj_coord, r->scene->cam->up);
	else if (key == 53)
		*obj_coord = vector_add(*obj_coord, r->scene->cam->orientation);
	else if (key == 54)
		*obj_coord = vector_sub(*obj_coord, r->scene->cam->orientation);
	else if ((key >= 55 && key <= 57) || key == 48)
		rotate_selected_obj(obj_normal, key, r);
}
