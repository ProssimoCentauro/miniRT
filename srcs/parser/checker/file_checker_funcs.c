/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:51:49 by rtodaro           #+#    #+#             */
/*   Updated: 2025/06/18 19:48:29 by rtodaro          ###   ########.fr       */
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
			exit_error(r, NULL, NULL, NULL);
		free(line);
		free_mat(mat);
	}
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
