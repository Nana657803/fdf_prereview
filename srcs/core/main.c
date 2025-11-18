/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:06:11 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/18 21:35:45 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	initialize_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->points = NULL;
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
	map->img_ptr = NULL;
	map->img_data = NULL;
	map->zoom_factor = DEFAULT_ZOOM;
	map->shift_x = WIN_WIDTH / 2;
	map->shift_y = WIN_HEIGHT / 2;
}

void	terminate_program(t_map *map, char *message, int exit_code)
{
	int	i;

	if (map->points)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->points[i])
				free(map->points[i]);
			i++;
		}
		free(map->points);
	}
	if (map->mlx_ptr)
	{
		if (map->img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->img_ptr);
		if (map->win_ptr)
			mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	if (message)
		ft_putendl_fd(message, 2);
	exit(exit_code);
}

static void	setup_mlx_environment(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		terminate_program(map, "Error: MLX initialization failed", 1);
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, WIN_TITLE);
	if (!map->win_ptr)
		terminate_program(map, "Error: Window creation failed", 1);
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!map->img_ptr)
		terminate_program(map, "Error: Image creation failed", 1);
	map->img_data = mlx_get_data_addr(map->img_ptr,
			&map->bits_per_pixel, &map->line_size, &map->endian);
}

static void	setup_event_hooks(t_map *map)
{
	mlx_hook(map->win_ptr, 2, 1L << 0, handle_keypress, map);
	mlx_hook(map->win_ptr, 17, 0L, handle_window_close, map);
	mlx_mouse_hook(map->win_ptr, handle_mouse, map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fdf <filename.fdf>", 2);
		return (1);
	}
	validate_file_extension(argv[1]);
	initialize_map(&map);
	load_map_file(argv[1], &map);
	setup_mlx_environment(&map);
	render_wireframe(&map);
	setup_event_hooks(&map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
