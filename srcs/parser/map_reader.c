/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:09:26 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/19 22:21:58 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	open_map_file(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		terminate_program(map, "Error: Cannot open file", 1);
	return (fd);
}

static void	calculate_map_size(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		elements_count;

	fd = open_map_file(filename, map);
	line = get_next_line(fd);
	while (line)
	{
		elements_count = count_line_elements(line);
		if (map->width == 0 && elements_count == 0)
			free_and_exit(line, -1, map, "Error: Newline at top of the file.");
		if (map->width == 0)
			map->width = elements_count;
		else if (elements_count != map->width)
			free_and_exit(line, -1, map, "Error: Map is not rectangular");
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
}

static void	allocate_map_memory(t_map *map)
{
	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		terminate_program(map, "Error: Memory allocation failed", 1);
}

static void	populate_map_data(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		row;

	fd = open_map_file(filename, map);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->points[row] = malloc(sizeof(t_point) * map->width);
		if (!map->points[row])
			free_and_exit(line, fd, map, "Error: Memory allocation failed");
		if (parse_coordinates(map->points[row], line, row, map->width))
			free_and_exit(line, fd, map, "Error: Z value out of range");
		free(line);
		row++;
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
}

void	load_map_file(char *filename, t_map *map)
{
	calculate_map_size(filename, map);
	if (map->width == 0 || map->height == 0)
	{
		get_next_line(-1);
		terminate_program(map, "Error: Invalid or empty map", 1);
	}
	allocate_map_memory(map);
	populate_map_data(filename, map);
}
