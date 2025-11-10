/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:09:41 by ndobashi          #+#    #+#             */
/*   Updated: 2025/11/10 14:09:43 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
