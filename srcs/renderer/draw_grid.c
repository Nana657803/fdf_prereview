/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:19 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/20 18:34:02 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	connect_horizontal(t_map *map, t_point **screen, int col, int row)
{
	if (col >= map->width - 1)
		return ;
	draw_line(map, screen[row][col], screen[row][col + 1], DEFAULT_COLOR);
}

static void	connect_vertical(t_map *map, t_point **screen, int col, int row)
{
	if (row >= map->height - 1)
		return ;
	draw_line(map, screen[row][col], screen[row + 1][col], DEFAULT_COLOR);
}

void	draw_grid(t_map *map, t_point **screen_points)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			set_pixel(map,  screen_points[row][col].x,  screen_points[row][col].y, DEFAULT_COLOR);
			connect_horizontal(map, screen_points, col, row);
			connect_vertical(map, screen_points, col, row);
			col++;
		}
		row++;
	}
}
