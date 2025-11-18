/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:51:34 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/18 20:58:30 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putc(t_line *line, char c)
{
	char	*new_str;
	size_t	i;

	if (line->length + 1 > line->capacity)
	{
		if (line->capacity == 0)
			line->capacity = 2;
		else
			line->capacity = line->capacity * 2;
		new_str = (char *)malloc(sizeof(char) * line->capacity);
		if (!new_str)
			return (0);
		i = 0;
		while (i < line->length)
		{
			if (line->string)
				new_str[i] = line->string[i];
			i++;
		}
		free(line->string);
		line->string = new_str;
	}
	line->string[line->length++] = c;
	return (1);
}

char	*get_next_line(int fd)
{
	t_line	line;
	char	c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_getc(-1), NULL);
	line.string = NULL;
	line.length = 0;
	line.capacity = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == READERROR)
			return (free(line.string), ft_getc(-1), NULL);
		if (c == '\0')
			break ;
		if (!ft_putc(&line, c))
			return (free(line.string), ft_getc(-1), NULL);
		if (c == '\n')
			break ;
	}
	if (line.length > 0 && !ft_putc(&line, '\0'))
		return (free(line.string), ft_getc(-1), NULL);
	return (line.string);
}
