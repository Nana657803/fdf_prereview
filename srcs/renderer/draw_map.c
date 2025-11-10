/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:19 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/10 14:10:21 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	clear_canvas(t_map *map)
{
	int	total_size;

	total_size = WIN_WIDTH * WIN_HEIGHT * (map->bits_per_pixel / 8);
	ft_bzero(map->img_data, total_size);
}

static void	connect_horizontal(t_map *map, int col, int row)
{
	t_point	current;
	t_point	next;

	if (col >= map->width - 1)
		return ;
	current = project_to_screen(map->points[row][col], map);
	next = project_to_screen(map->points[row][col + 1], map);
	draw_line(map, current, next, DEFAULT_COLOR);
}

static void	connect_vertical(t_map *map, int col, int row)
{
	t_point	current;
	t_point	below;

	if (row >= map->height - 1)
		return ;
	current = project_to_screen(map->points[row][col], map);
	below = project_to_screen(map->points[row + 1][col], map);
	draw_line(map, current, below, DEFAULT_COLOR);
}

void	render_wireframe(t_map *map)
{
	int	col;
	int	row;

	clear_canvas(map);
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			connect_horizontal(map, col, row);
			connect_vertical(map, col, row);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_ptr, 0, 0);
}
