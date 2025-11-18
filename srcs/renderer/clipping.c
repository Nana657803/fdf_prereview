/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:06:06 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/18 22:50:51 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	point_in_bounds(t_point point)
{
	return (point.x >= 0 && point.x < WIN_WIDTH && point.y >= 0
		&& point.y < WIN_HEIGHT);
}

int	line_completely_outside(t_point start, t_point end)
{
	int	margin;

	margin = 50;
	if (start.x < -margin && end.x < -margin)
		return (1);
	if (start.x > WIN_WIDTH + margin && end.x > WIN_WIDTH + margin)
		return (1);
	if (start.y < -margin && end.y < -margin)
		return (1);
	if (start.y > WIN_HEIGHT + margin && end.y > WIN_HEIGHT + margin)
		return (1);
	return (0);
}

int	point_roughly_visible(t_point point)
{
	int	margin;

	margin = 200;
	return (point.x >= -margin && point.x < WIN_WIDTH + margin && point.y
		>= -margin && point.y < WIN_HEIGHT + margin);
}
