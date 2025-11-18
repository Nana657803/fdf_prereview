/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:51:30 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/18 21:24:23 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	reset_buffer(char **buff, char **buffptr, int *read_byte)
{
	if (*buff)
		free(*buff);
	*buff = NULL;
	*buffptr = NULL;
	*read_byte = 0;
}

static char	read_buffer(int fd, char **buff, char **buffptr, int *read_byte)
{
	*read_byte = read(fd, *buff, BUFFER_SIZE);
	if (*read_byte < 0)
		return (reset_buffer(buff, buffptr, read_byte), READERROR);
	if (*read_byte == 0)
		return (reset_buffer(buff, buffptr, read_byte), '\0');
	*buffptr = *buff;
	return ((*read_byte)--, *(*buffptr)++);
}

char	ft_getc(int fd)
{
	static char	*buff = NULL;
	static char	*buffptr = NULL;
	static int	read_byte = 0;

	if (fd < 0)
		return (reset_buffer(&buff, &buffptr, &read_byte), '\0');
	if (!buff)
	{
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buff)
			return (READERROR);
	}
	if (read_byte <= 0)
		return (read_buffer(fd, &buff, &buffptr, &read_byte));
	return (read_byte--, *buffptr++);
}
