#include "minirt.h"

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
		modify_rgb(colors, ft_atoi(rgb[i]), i);
		i++;
	}
	free_mat(rgb);
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
		modify_vector(coords, ft_atod(mat[i]), i);
		i++;
	}
	free_mat(mat);
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
		modify_vector(normal, ft_atod(mat[i]), i);
		i++;
	}
	free_mat(mat);
	return (0);
}
