#include "minirt.h"


size_t	count_lines(char **mat);

int is_valid_integer(char *str)
{
    int i = 0;
    int has_digit = 0;

    if (str[0] == '\0')
        return (1);
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] != '\0')
	{
        if (ft_isdigit(str[i]))
            has_digit = 1;
		else
            return (1);
        i++;
    }
    if (!has_digit)
        return (1);
    return (0);
}

double	ft_atod(char *str)
{
	double	res;
	size_t	i;
	size_t	j;
	int		sign;

	i = 0;
	j = 1;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + (str[i++] - '0');
	if (str[i++] == '\0')
		return (res * sign);
	while (str[i])
	{
		res += ((str[i++] - '0') / pow(10, j));
		j++;
	}
	return (res * sign);
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

size_t	count_lines(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	check_ratio(char *ratio, double *num)
{
	if (ratio[0] == '0')
	{
		if (ratio[1] != '.')
			return (1);
		if (ratio[2] < '0' && ratio[2] > '9')
			return (1);
	}
	else if (ratio[0] == '1')
	{
		if (ratio[1] != '.')
			return (1);
		if (ratio[2] != '0')
			return (1);
	}
	else
		return (1);
	*num = ft_atod(ratio);
	return (0);
}

int	is_valid_rgb_component(char *str)
{
	int	i;
	int	value;

	i = 0;
	if (!str || str[0] == '\0' || ft_strlen(str) > 3)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (1);
		i++;
	}
	value = ft_atoi(str);
	if (value < 0 || value > 255)
		return (1);
	return (0);
}

int	check_colors(char *line, t_rgb* colors)
{
	char	**rgb;
	int i;

	rgb = ft_split(line, ',');
	i = 0;
	if (count_lines(rgb) != 3)
	{
		free_mat(rgb);
		return (1);
	}
	while (rgb[i])
	{
		if (is_valid_rgb_component(rgb[i]))
		{
			free_mat(rgb);
			return (1);
		}
		if (i == 0)
			colors->r = ft_atoi(rgb[i]);
		else if (i == 1)
			colors->g = ft_atoi(rgb[i]);
		else if (i == 2)
			colors->b = ft_atoi(rgb[i]);
		i++;
	}
	free_mat(rgb);
	return (0);
}


int is_valid_double(char *str, double *num)
{
    int i = 0;
    int dot_count = 0;
    int has_digit = 0;

	if (str[0] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (1);
		}
		else
			return (1);
		i++;
	}
	if (!has_digit)
	{
		return (1);
	}
	if (num)
		*num = ft_atod(str);
	return (0);
}

int	check_coordinates(char *line, t_vector *coords)
{
	char	**mat;
	int i;

	mat = ft_split(line, ',');
	i = 0;
	if (count_lines(mat) != 3)
	{
		free_mat(mat);
		return (1);
	}
	while (mat[i])
	{
		if (is_valid_double(mat[i], NULL))
		{
			free_mat(mat);
			return (1);
		}
		if (i == 0)
			coords->x = ft_atod(mat[i]);
		else if (i == 1)
			coords->y = ft_atod(mat[i]);
		else if (i == 2)
			coords->z = ft_atod(mat[i]);
		i++;
	}
	free_mat(mat);
	return (0);
}

int is_valid_vector_range(char* str)
{
	double	res;
	
	if (is_valid_double(str, NULL))
		return (1);
	res = ft_atod(str);
	if (res < -1.0 || res > 1.0)
		return (1);
	return (0);
}

int	check_normal(char *line, t_vector *normal)
{
	char	**mat;
	int i;

	mat = ft_split(line, ',');
	i = 0;
	if (count_lines(mat) != 3)
	{
		free_mat(mat);
		return (1);
	}
	while (mat[i])
	{
		if (is_valid_vector_range(mat[i]))
		{
			free_mat(mat);
			return (1);
		}
		if (i == 0)
			normal->x = ft_atod(mat[i]);
		else if (i == 1)
			normal->y = ft_atod(mat[i]);
		else if (i == 2)
			normal->z = ft_atod(mat[i]);
		i++;
	}
	free_mat(mat);
	return (0);
}

int  check_fov(char *line, double *num)
{
	int res;

	if (is_valid_integer(line))
		return (1);
	res = ft_atoi(line);
	if (res < 0 || res > 180)
		return (1);
	*num = ft_atod(line);
	return (0);
}

int check_camera(char **line, t_renderer *r)
{
	t_camera		*cam;
	t_object_data	data;
	data.type = CAMERA;

	if (r->data->cameras == 1)
		return (1);
	if (count_lines(line) != 4)
		return (1);
	if (check_coordinates(line[1], &(data).coord))
		return (1);
	if (check_normal(line[2], &(data).normal))
		return (1);
	if (check_fov(line[3], &(data).fov))
		return (1);
	r->data->cameras++;
	create_from_data(&data, (void **)&cam);
	r->scene->cam = *cam;
	free(cam);
	print_object_data(data);
	return (0);
}

int	check_amb_light(char **line, t_renderer *r)
{
	t_ambient		*a_light;
	t_object_data	data;

	data.type = A_LIGHT;
	if (r->data->a_lights == 1)
		return (-1);
	if (count_lines(line) != 3)
		return (1);
	if (check_ratio(line[1], &(data).ratio))
		return (1);
	if (check_colors(line[2], &(data).rgb))
		return (1);
	r->data->a_lights++;
	create_from_data(&data, (void **)&a_light);
	r->scene->amb = *a_light;
	free(a_light);
	print_object_data(data);
	return (0);
}

int	check_light(char **line, t_renderer *r)
{
	t_light		*light;
	t_object_data	data;

	data.type = LIGHT;
	if (count_lines(line) != 4)
		return (1);
	if (check_coordinates(line[1], &(data).coord))
		return (1);
	if (check_ratio(line[2], &(data).brightness))
		return (1);
	if (check_colors(line[3], &(data).rgb))
		return (1);
	create_from_data(&data, (void **)&light);
	add_light(r->scene, light);
	print_object_data(data);
	return (0);
}

int	check_sphere(char **line, t_renderer *r)
{
	t_object		*sp;
	t_object_data	data;

	data.type = SPHERE;
	if (count_lines(line) != 4)
		return (1);
	if (check_coordinates(line[1], &(data).coord))
		return (1);
	if (is_valid_double(line[2], &(data).diameter))
		return (1);
	if (check_colors(line[3], &(data).rgb))
		return (1);
	create_from_data(&data, (void **)&sp);
	add_object(r->scene, sp);
	print_object_data(data);
	return (0);
}

int	check_plane(char **line, t_renderer *r)
{
	t_object		*pl;
	t_object_data	data;

	data.type = PLANE;
	if (count_lines(line) != 4)
		return (1);
	if (check_coordinates(line[1], &(data).coord))
		return (1);
	if (check_normal(line[2], &(data).normal))
		return (1);
	if (check_colors(line[3], &(data).rgb))
		return (1);
	create_from_data(&data, (void **)&pl);
	add_object(r->scene, pl);
	print_object_data(data);
	return (0);
}

//da finire
int	check_cylinder(char **line, t_renderer *r)
{
	t_object		*cy;
	t_object_data	data;
	
	data.type = CYLINDER;
	if (count_lines(line) != 6)
		return (1);
	if (check_coordinates(line[1], &(data).coord))
		return (1);
	if (check_normal(line[2], &(data).normal))
		return (1);
	if (is_valid_double(line[3], &(data).diameter))
		return (1);
	if (is_valid_double(line[4], &(data).height))
		return (1);
	if (check_colors(line[5], &(data).rgb))
		return (1);
	create_from_data(&data, (void **)&cy);
	add_object(r->scene, cy);
	print_object_data(data);
	return (0);
}

int	detect_checker(char **line, t_renderer *r)
{
	if (!ft_strncmp(*line, "A\0", 2))
		return (check_amb_light(line, r));
	if (!ft_strncmp(*line, "C\0", 2))
		return (check_camera(line, r));
	if (!ft_strncmp(*line, "L\0", 2))
		return (check_light(line, r));
	if (!ft_strncmp(*line, "sp\0", 3))
		return (check_sphere(line, r));
	if (!ft_strncmp(*line, "pl\0", 3))
		return (check_plane(line, r));
	if (!ft_strncmp(*line, "cy\0", 3))
		return (check_cylinder(line, r));
	return (1);
}

int	check_line(char **line, t_renderer *r)
{
	if (detect_checker(line, r))
		return (1);
	return (0);
}

int	not_empty_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '\n' || !*line)
		return (1);
	return (0);
}

int	check_file(t_renderer *r)
{
	int	fd;
	char	*line;
	char	**mat;

	fd = open(r->data->file, 0, O_WRONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			exit_error(r, NON_EXISTENT_FILE_ERROR, NULL);
		else
			exit_error(r, FILE_OPENING_ERROR, NULL);
    }
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (not_empty_line(line))
		{
			free(line);
			continue;
		}
		mat = ft_split2(line, " \t\n");
		if (!mat)
		{
			free(line);
			break ;
		}
		if (check_line(mat, r))
			exit_error(r, ERROR, SYNTAX_ERROR);
		free(line);
		free_mat(mat);
	}
	print_scene(r->scene);
	printf(VALID_FILE_MSG);
	return (0);
}


void	check_args(int ac, char *file)
{
	size_t	len = 0;
	int		check = 1;

	if (ac != 2)
	{
		print_error(ARGS_ERROR, NULL);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(file);
	check = file[len - 3] == '.' && file[len - 2] == 'r' && file[len - 1] == 't';
	if (len < 4)
		check = 0;
	if (!check)
	{
		print_error(NOT_RT_FILE_ERROR, NULL);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_renderer	*renderer;

	check_args(ac, av[1]);

	renderer = init_renderer(av[1]);
	check_file(renderer);
	free_renderer(renderer);
	return (0);
}
