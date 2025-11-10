/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:00:07 by ndobashi          #+#    #+#             */
/*   Updated: 2025/04/27 15:31:11 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result > LONG_MAX / 10 || (result == LONG_MAX / 10 && 7 < (*str
						- '0'))) && sign == 1)
			return ((int)LONG_MAX);
		if ((result > LONG_MAX / 10 || (result == LONG_MAX / 10 && 8 < (*str
						- '0'))) && sign == -1)
			return ((int)LONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d, %d\n", atoi("9223372036854775808"),
// 		ft_atoi("9223372036854775808"));
// 	printf("%d, %d\n", atoi("-922337203685477580009"),
// 		ft_atoi("-922337203685477580009"));
// 	return(0);
// }
