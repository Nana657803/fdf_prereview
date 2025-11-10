/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:00:48 by ndobashi          #+#    #+#             */
/*   Updated: 2025/04/24 22:00:49 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	new_s = malloc(len);
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, s, len);
	return (new_s);
}
