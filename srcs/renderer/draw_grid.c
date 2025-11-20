/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:19 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/20 21:23:17 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	has_z_sign_change(t_map *map, int row1, int col1, int row2,
		int col2)
{
	int	z1;
	int	z2;

	z1 = map->points[row1][col1].z;
	z2 = map->points[row2][col2].z;
	if (z1 * z2 < 0)
		return (1);
	return (0);
}
static int	point_roughly_visible(t_point point)
{
	int	margin;

	margin = 200;
	return (point.x >= -margin && point.x < WIN_WIDTH + margin && point.y >=
		-margin && point.y < WIN_HEIGHT + margin);
}

static void	connect_horizontal(t_map *map, t_point **screen, int col, int row)
{
	if (col >= map->width - 1)
		return ;
	if (!point_roughly_visible(screen[row][col])
		&& !point_roughly_visible(screen[row][col + 1])
		&& !has_z_sign_change(map, row, col, row, col + 1))
	{
		return ;
	}
	draw_line(map, screen[row][col], screen[row][col + 1], DEFAULT_COLOR);
}

static void	connect_vertical(t_map *map, t_point **screen, int col, int row)
{
	if (row >= map->height - 1)
		return ;
	if (!point_roughly_visible(screen[row][col])
		&& !point_roughly_visible(screen[row + 1][col])&& !has_z_sign_change(map, row, col, row+ 1, col))
	{
		return ;
	}
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
			set_pixel(map, screen_points[row][col].x, screen_points[row][col].y,
				DEFAULT_COLOR);
			connect_horizontal(map, screen_points, col, row);
			connect_vertical(map, screen_points, col, row);
			col++;
		}
		row++;
	}
}
