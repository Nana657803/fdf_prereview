/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_scale_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:05:10 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/20 16:05:12 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	z_scale_up(t_map *map)
{
	if (map->z_scale_factor < Z_SCALE_MAX)
	{
		map->z_scale_factor += 0.1;
		render_wireframe(map);
	}
}

void	z_scale_down(t_map *map)
{
	if (map->z_scale_factor > Z_SCALE_MIN)
	{
		map->z_scale_factor -= 0.1;
		render_wireframe(map);
	}
}
