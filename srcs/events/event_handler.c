/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:24:47 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/19 23:15:14 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

#include <stdio.h>

void	z_scale_up(t_map *map)
{
	if(map->z_scale_factor < Z_SCALE_MAX)
	{
		map->z_scale_factor += 0.1;
		render_wireframe(map);
	}
}

void	z_scale_down(t_map *map)
{
	if(map->z_scale_factor > Z_SCALE_MIN)
	{
		map->z_scale_factor -= 0.1;
		render_wireframe(map);
	}
}

int	handle_keypress(int keycode, t_map *map)
{
	if (keycode == XK_Escape)
		terminate_program(map, NULL, 0);
	else if (keycode == XK_r)
		z_scale_up(map);
	else if (keycode == XK_f)
		z_scale_down(map);
	return (0);
}

static int	zoom_in(t_map *map)
{
	double	new_zoom;

	new_zoom = map->zoom_factor * ZOOM_STEP;
	if (new_zoom > MAX_ZOOM)
		return (0);
	map->zoom_factor = new_zoom;
	return (1);
}

static int	zoom_out(t_map *map)
{
	double	new_zoom;

	new_zoom = map->zoom_factor / ZOOM_STEP;
	if (new_zoom < MIN_ZOOM)
		return (0);
	map->zoom_factor = new_zoom;
	return (1);
}

int	handle_mouse(int button, int x, int y, t_map *map)
{
	int	zoom_changed;

	(void)x;
	(void)y;
	zoom_changed = 0;
	if (button == MOUSE_SCROLL_UP)
		zoom_changed = zoom_in(map);
	else if (button == MOUSE_SCROLL_DOWN)
		zoom_changed = zoom_out(map);
	if (zoom_changed)
		render_wireframe(map);
	return (0);
}

int	handle_window_close(t_map *map)
{
	terminate_program(map, NULL, 0);
	return (0);
}
