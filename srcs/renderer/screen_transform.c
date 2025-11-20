/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:25:26 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/20 17:32:16 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**allocate_screen_points(t_map *map)
{
	t_point	**screen_points;
	int		i;

	screen_points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!screen_points)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		screen_points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!screen_points[i])
		{
			while (--i >= 0)
				free(screen_points[i]);
			free(screen_points);
			return (NULL);
		}
		i++;
	}
	return (screen_points);
}

void	free_screen_points(t_point **screen_points, int height)
{
	int	i;

	if (!screen_points)
		return ;
	i = 0;
	while (i < height)
	{
		if (screen_points[i])
			free(screen_points[i]);
		i++;
	}
	free(screen_points);
}

void	screen_transform(t_map *map, t_point **screen_points)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			screen_points[row][col] = project_to_screen(map->points[row][col],
					map);
			col++;
		}
		row++;
	}
}
