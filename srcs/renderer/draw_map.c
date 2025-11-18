/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:19 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/18 22:27:04 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	clear_canvas(t_map *map)
{
	int	total_size;

	total_size = WIN_WIDTH * WIN_HEIGHT * (map->bits_per_pixel / 8);
	ft_bzero(map->img_data, total_size);
}

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

static void	draw_all_connections(t_map *map, t_point **screen_points)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			connect_horizontal(map, screen_points, col, row);
			connect_vertical(map, screen_points, col, row);
			col++;
		}
		row++;
	}
}

void	render_wireframe(t_map *map)
{
	t_point	**screen_points;

	clear_canvas(map);
	screen_points = allocate_screen_points(map);
	if (!screen_points)
		terminate_program(map, "Error: Memory allocation failed", 1);
	precompute_screen_points(map, screen_points);
	draw_all_connections(map, screen_points);
	free_screen_points(screen_points, map->height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}
