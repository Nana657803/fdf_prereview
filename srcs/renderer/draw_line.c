/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:32 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/19 22:21:11 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_map *map, int x, int y, int color)
{
	int		offset;
	int		bytes_per_pixel;
	char	*pixel;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		bytes_per_pixel = map->bits_per_pixel / 8;
		offset = (y * map->line_size) + (x * bytes_per_pixel);
		pixel = map->img_data + offset;
		*(unsigned int *)pixel = color;
	}
}

static void	init_line_drawer(t_point start, t_point end, t_line_drawer *drawer)
{
	drawer->delta_x = abs(end.x - start.x);
	drawer->delta_y = abs(end.y - start.y);
	if (start.x < end.x)
		drawer->step_x = 1;
	else
		drawer->step_x = -1;
	if (start.y < end.y)
		drawer->step_y = 1;
	else
		drawer->step_y = -1;
	drawer->error = drawer->delta_x - drawer->delta_y;
}

static int	line_not_finished(t_point current, t_point end)
{
	return (current.x != end.x || current.y != end.y);
}

static void	advance_line(t_point *current, t_line_drawer *drawer)
{
	drawer->error_temp = 2 * drawer->error;
	if (drawer->error_temp > -drawer->delta_y)
	{
		drawer->error -= drawer->delta_y;
		current->x += drawer->step_x;
	}
	if (drawer->error_temp < drawer->delta_x)
	{
		drawer->error += drawer->delta_x;
		current->y += drawer->step_y;
	}
}

void	draw_line(t_map *map, t_point start, t_point end, int color)
{
	t_line_drawer	drawer;

	init_line_drawer(start, end, &drawer);
	while (1)
	{
		set_pixel(map, start.x, start.y, color);
		if (!line_not_finished(start, end))
			break ;
		advance_line(&start, &drawer);
	}
}
