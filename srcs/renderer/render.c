/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:20:09 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/20 17:37:21 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	clear_canvas(t_map *map)
{
	int	total_size;

	total_size = WIN_WIDTH * WIN_HEIGHT * (map->bits_per_pixel / 8);
	ft_bzero(map->img_data, total_size);
}

void	render_wireframe(t_map *map)
{
	t_point	**screen_points;

	clear_canvas(map);
	screen_points = allocate_screen_points(map);
	if (!screen_points)
		terminate_program(map, "Error: Memory allocation failed", 1);
	screen_transform(map, screen_points);
	draw_grid(map, screen_points);
	free_screen_points(screen_points, map->height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}
