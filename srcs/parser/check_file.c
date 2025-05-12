#include "minirt.h"



int	detect_checker(char *line)
{
	if (!ft_strncmp(line, "A ", 2) || !ft_strncmp(line, "A\t", 2))
		return (check_amb_light(line));
	if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C\t", 2))
		return (check_camera(line));
	if (!ft_strncmp(line, "L ", 2) || !ft_strncmp(line, "L\t", 2))
		return (check_light(line));
	if (!ft_strncmp(line, "sp ", 3) || !ft_strncmp(line, "sp\t", 3))
		return (check_sphere(line));
	if (!ft_strncmp(line, "pl ", 3) || !ft_strncmp(line, "pl\t", 3))
		return (check_plane(line));
	if (!ft_strncmp(line, "cy ", 3) || !ft_strncmp(line, "cy\t", 3))
		return (check_cylinder(line));
	return (1);
}

int	check_file(t_data *data)
{
	int	fd;
	char	*line;

	fd = open(data->line, NULL, W_RDONLY);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_line(line))
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
