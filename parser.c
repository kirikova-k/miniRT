/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:10:10 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 15:14:27 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	clear_arr_line(char **arr, char *line)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(line);
}

static void	format_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == ',')
			line[i] = ' ';
		if (i > 1 && !(line[i] == ' ' || line[i] == '\t' || \
			line[i] == ',' || line[i] == '.' || line[i] == '-' || \
			ft_isdigit(line[i])))
			exit_error("Corrupted file");
		i++;
	}
}

static void	create_objects(char **arr, t_data *data)
{
	static int	count = -1;

	if (!ft_strcmp(arr[0], "A"))
		create_ambient(arr, data);
	else if (!ft_strcmp(arr[0], "C"))
		create_camera(arr, data);
	else if (!ft_strcmp(arr[0], "L"))
		data->objects[count] = create_light(arr, &count, data);
	else if (!ft_strcmp(arr[0], "sp"))
		data->objects[count] = create_sphere(arr, &count, data);
	else if (!ft_strcmp(arr[0], "pl"))
		data->objects[count] = create_plane(arr, &count, data);
	else if (!ft_strcmp(arr[0], "cy"))
		data->objects[count] = create_cylinder(arr, &count, data);
	else
		exit_error("Corrupted file");
}

int	count_objects(char *file_name)
{
	int		fd;
	char	*line;
	int		check_read;
	int		count;

	if (ft_strcmp(&file_name[ft_strlen(file_name) - 3], ".rt"))
		exit_error("Wrong file extention");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error("Can't open file");
	check_read = 1;
	count = 0;
	while (check_read > 0)
	{
		check_read = get_next_line(fd, &line);
		if (check_read == -1)
			exit_error("Can't read file");
		if (line[0] == 'p' || line[0] == 's' || \
			line[0] == 'c' || line[0] == 'L')
			count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	parser(char *file_name, t_data *data)
{
	char	*line;
	int		fd;
	int		check_read;
	char	**arr;

	data->qty = count_objects(file_name);
	data->objects = malloc(sizeof(t_object *) * data->qty);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error("Error while opening file");
	check_read = 1;
	while (check_read > 0)
	{
		check_read = get_next_line(fd, &line);
		if (check_read == -1)
			exit_error("Error while reading file");
		format_line(line);
		arr = ft_split(line, ' ');
		if (!arr)
			exit_error("Malloc error in split");
		if (arr[0])
			create_objects(arr, data);
		clear_arr_line(arr, line);
	}
	close (fd);
}
