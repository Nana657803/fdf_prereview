/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:09:41 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/18 21:36:56 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	validate_file_extension(char *filename)
{
	int		len;
	char	*extension;

	len = ft_strlen(filename);
	if (len < 5)
	{
		ft_putendl_fd("Error: Invalid file extension (expected .fdf)", 2);
		exit(1);
	}
	extension = filename + len - 4;
	if (ft_strncmp(extension, ".fdf", 4) != 0)
	{
		ft_putendl_fd("Error: Invalid file extension (expected .fdf)", 2);
		exit(1);
	}
}

int	count_line_elements(char *line)
{
	int		count;
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	count = 0;
	while (tokens[count] && tokens[count][0] != '\n')
		count++;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (count);
}

void	parse_coordinates(t_point *points, char *line, int row, int width)
{
	char	**tokens;
	int		col;
	int		i;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return ;
	col = 0;
	while (col < width)
	{
		points[col].x = col;
		points[col].y = row;
		points[col].z = ft_atoi(tokens[col]);
		col++;
	}
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
