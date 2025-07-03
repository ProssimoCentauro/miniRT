/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:49 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/03 15:49:48 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	not_empty_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '\n' || !*line)
		return (1);
	return (0);
}

static void	loop_exit_error(t_renderer *r, char *line, char **mat, int *fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(*fd);
	}
	free_mat(mat);
	close(*fd);
	exit_error(r, NULL, NULL, NULL);
}

static void	checker_loop(t_renderer *r, int *fd)
{
	char	*line;
	char	**mat;

	while (42)
	{
		line = get_next_line(*fd);
		if (!line)
			break ;
		if (not_empty_line(line))
		{
			free(line);
			continue ;
		}
		mat = ft_split2(line, " \t\n");
		if (!mat)
		{
			free(line);
			break ;
		}
		if (detect_checker(mat, r))
			loop_exit_error(r, line, mat, fd);
		free(line);
		free_mat(mat);
	}
	close(*fd);
}

int	check_file(t_renderer *r)
{
	int	fd;

	fd = open(r->data->file, 0, O_WRONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			exit_error(r, NON_EXISTENT_FILE_ERROR, NULL, NULL);
		else
			exit_error(r, FILE_OPENING_ERROR, NULL, NULL);
	}
	checker_loop(r, &fd);
	check_scene(r);
	print_scene(r->scene);
	printf(VALID_FILE_MSG);
	return (0);
}
