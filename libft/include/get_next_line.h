/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:51:38 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/18 17:08:33 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define READERROR -2

typedef struct s_line
{
	char	*string;
	size_t	length;
	size_t	capacity;
}	t_line;

char	*get_next_line(int fd);
char	ft_getc(int fd);
int		ft_putc(t_line *line, char c);

#endif
