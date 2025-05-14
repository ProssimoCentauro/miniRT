#include "minirt.h"

void	free_mat(char **mat)
{
	while (*mat)
	{
		free(*mat);
		mat++
	}
	free(mat);
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

int	check_ratio(char *ratio)
{
	if (ratio[0] == '0')
	{
		if (ratio[1] != '.')
			return (1);
		if (ratio[2] < '0' && ratio[2] > '9')
			return (1);
	}
	if (ratio[0] == '1')
	{
		if (ratio[1] != '.')
			return (1);
		if (ratio[2] != '0')
			return (1);
	}
	else
		return (1);
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

int	check_colors(char *line)
{
	char	**mat;
	int i;

	mat = ft_split(line);
	i = 0;
	if (count_lines(mat != 3))
	{
		free_mat(mat);
		return (1);
	}
	while (rgb[i])
	{
		if (is_valid_rgb_component(rgb[i]))
		{
			free_mat(mat);
			return (1);
		}
		i++;
	}
	return (0);

}

int	check_amb_light(char **line)
{
	if (count_lines(line) != 3)
		return (1);
	if (check_ratio(line[1]))
		return (1);
	if (check_colors(line[2]))
		return (1);
}

int	detect_checker(char **line)
{
	if (!ft_strncmp(*line, "A\0", 2))
		return (check_amb_light(line));
	if (!ft_strncmp(*line, "C\0", 2))
		return (check_camera(line));
	if (!ft_strncmp(*line, "L\0", 2))
		return (check_light(line));
	if (!ft_strncmp(*line, "sp\0", 3))
		return (check_sphere(line));
	if (!ft_strncmp(*line, "pl\0", 3))
		return (check_plane(line));
	if (!ft_strncmp(*line, "cy\0", 3))
		return (check_cylinder(line));
	return (1);
}

int	check_line(char **line)
{
	if (detect_checker(line))
		return (1);
}

int	check_file(t_data *data)
{
	int	fd;
	char	*line;
	char	**mat;

	fd = open(data->line, NULL, W_RDONLY);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mat = ft_split2(line, " \t");
		if (!mat)
		{
			free(line);
			break ;
		}	
		if (check_line(mat))
			exit_error(data, "Error" "INVALID SYNTAX!");
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	if (ac != 2)
	{
		print_error("INVALID ARGUMENTS!", NULL);
		exit(EXIT_FAILURE);
	}
	data = initialize_data(av[1]);
	check_file(t_data *data);
}
