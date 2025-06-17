/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:49 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/17 16:19:59 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	check_scene(t_renderer *r)
{
	t_scene *s = r->scene;

	if (!s->cam && !s->amb && !s->objs && !s->lights)
		exit_error(r, GENERAL_ERROR, EMPTY_FILE_ERROR, NULL);
	else if (!s->cam)
		exit_error(r, SYNTAX_ERROR, MISSING_ERROR, CAM_MSG);
	else if (!s->amb)
		exit_error(r, SYNTAX_ERROR, MISSING_ERROR, A_LIGHT_MSG);
	else if (!s->lights)
		exit_error(r, SYNTAX_ERROR, MISSING_ERROR, LIGHT_MSG);
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
			exit_error(r, NON_EXISTENT_FILE_ERROR, NULL, NULL);
		else
			exit_error(r, FILE_OPENING_ERROR, NULL, NULL);
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
			exit_error(r, NULL, NULL, NULL);
		free(line);
		free_mat(mat);
	}
	check_scene(r);
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
		print_error(ARGS_ERROR, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(file);
	check = file[len - 3] == '.' && file[len - 2] == 'r' && file[len - 1] == 't';
	if (len < 4)
		check = 0;
	if (!check)
	{
		print_error(NOT_RT_FILE_ERROR, NULL, NULL);
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
