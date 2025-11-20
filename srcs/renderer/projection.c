/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:07 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/20 20:25:33 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	apply_scaling(t_point point, t_map *map)
{
	point.x *= map->zoom_factor;
	point.y *= map->zoom_factor;
	point.z *= map->zoom_factor * map->z_scale_factor;
	return (point);
}

static t_point	center_to_origin(t_point point, t_map *map)
{
	point.x -= (map->width * map->zoom_factor) / 2;
	point.y -= (map->height * map->zoom_factor) / 2;
	return (point);
}

static t_point	isometric_transform(t_point point)
{
	t_point	result;
	double	temp_x;

	temp_x = point.x;
	result.x = (temp_x - point.y) * COS_30;
	result.y = (temp_x + point.y) * SIN_30 - point.z;
	result.z = point.z;
	return (result);
}

static t_point	translate_to_screen(t_point point, t_map *map)
{
	point.x += map->shift_x;
	point.y += map->shift_y;
	return (point);
}

t_point	project_to_screen(t_point point, t_map *map)
{
	point = apply_scaling(point, map);
	point = center_to_origin(point, map);
	point = isometric_transform(point);
	point = translate_to_screen(point, map);
	return (point);
}
