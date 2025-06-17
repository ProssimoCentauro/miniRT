#include "minirt.h"

int check_camera(char **line, t_renderer *r)
{
	t_camera		*cam;
	t_object_data	data;
	data.type = CAMERA;

	if (r->data->cameras == 1)
		return (launch_error(1, SYNTAX_ERROR, TOO_MANY, CAM_MSG));
	if (count_lines(line) != 4)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, CAM_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, CAM_MSG));
	if (check_normal(line[2], &(data).normal))
		return (launch_error(1, SYNTAX_ERROR, NORMAL_ERROR, CAM_MSG));
	if (check_fov(line[3], &(data).fov))
		return (launch_error(1, SYNTAX_ERROR, FOV_ERROR, CAM_MSG));
	r->data->cameras++;
	create_from_data(&data, (void **)&cam);
	r->scene->cam = cam;
	//print_object_data(data);
	return (0);
}


int	check_amb_light(char **line, t_renderer *r)
{
	t_ambient		*a_light;
	t_object_data	data;

	data.type = A_LIGHT;
	if (r->data->a_lights == 1)
		return (launch_error(1, SYNTAX_ERROR, TOO_MANY, A_LIGHT_MSG));
	if (count_lines(line) != 3)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, A_LIGHT_MSG));
	if (check_ratio(line[1], &(data).ratio))
		return (launch_error(1, SYNTAX_ERROR, RATIO_ERROR, A_LIGHT_MSG));
	if (check_colors(line[2], &(data).rgb))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, A_LIGHT_MSG));
	r->data->a_lights++;
	create_from_data(&data, (void **)&a_light);
	r->scene->amb = a_light;
	//print_object_data(data);
	return (0);
}


int	check_light(char **line, t_renderer *r)
{
	t_light		*light;
	t_object_data	data;

	data.type = LIGHT;
	if (count_lines(line) != 4)
		return (launch_error(1, SYNTAX_ERROR, INVALID_PARAMS, LIGHT_MSG));
	if (check_coordinates(line[1], &(data).coord))
		return (launch_error(1, SYNTAX_ERROR, COORD_ERROR, LIGHT_MSG));
	if (check_ratio(line[2], &(data).brightness))
		return (launch_error(1, SYNTAX_ERROR, RATIO_ERROR, LIGHT_MSG));
	if (check_colors(line[3], &(data).rgb))
		return (launch_error(1, SYNTAX_ERROR, COLOR_ERROR, LIGHT_MSG));
	create_from_data(&data, (void **)&light);
	add_light(r->scene, light);
	//print_object_data(data);
	return (0);
}
