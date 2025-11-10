/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:07:58 by ndobashi          #+#    #+#             */
/*   Updated: 2025/04/27 13:15:20 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	term_counter(char const *s, char c)
{
	size_t	count;
	int		in_term;

	count = 0;
	in_term = 0;
	while (*s)
	{
		if (!in_term && *s != c)
		{
			count++;
			in_term = 1;
		}
		else if (in_term && *s == c)
			in_term = 0;
		s++;
	}
	return (count);
}

static void	split_free(char **result, int count)
{
	while (count > 0)
	{
		free(result[count - 1]);
		count--;
	}
	free(result);
}

static char	*ft_strndup(char const *src, size_t size)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, src, size + 1);
	return (result);
}

static int	split_dup(char **result, char const *s, char c, size_t i)
{
	size_t	split_len;

	split_len = 0;
	while (s[split_len] && s[split_len] != c)
		split_len++;
	result[i] = ft_strndup(s, split_len);
	if (!result[i])
	{
		split_free(result, i);
		return (0);
	}
	i++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	size = term_counter(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		if (split_dup(result, s, c, i) != 1)
			return (0);
		while (*s && *s != c)
			s++;
		i++;
	}
	result[i] = 0;
	return (result);
}
