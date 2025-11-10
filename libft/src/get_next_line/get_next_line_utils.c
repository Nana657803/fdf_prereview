/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:51:30 by ndobashi          #+#    #+#             */
/*   Updated: 2025/05/10 15:07:08 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_getc(int fd)
{
	static char	*buff = NULL;
	static char	*buffptr = NULL;
	static int	read_byte = 0;

	if (!buff)
	{
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buff)
			return (READERROR);
	}
	if (read_byte <= 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte < 0)
			return (free(buff), buff = NULL, buffptr = NULL,
				read_byte = 0, READERROR);
		if (read_byte == 0)
			return (free(buff), buff = NULL, buffptr = NULL, '\0');
		buffptr = buff;
	}
	return (read_byte--, *buffptr++);
}
