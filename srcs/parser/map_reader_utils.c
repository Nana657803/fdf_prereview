/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:02:44 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/19 22:22:13 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_and_exit(char *line, int fd, t_map *map, char *msg)
{
	free(line);
	if (fd > 2)
		close(fd);
	get_next_line(-1);
	terminate_program(map, msg, 1);
}
