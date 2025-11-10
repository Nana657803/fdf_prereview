/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:04:35 by ndobashi          #+#    #+#             */
/*   Updated: 2025/09/30 21:12:51 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, char format)
{
	int		count;
	char	*hex_digits;

	count = 0;
	if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (num >= 16)
	{
		count += ft_puthex(num / 16, format);
		count += ft_puthex(num % 16, format);
	}
	else
		count += ft_putchar(hex_digits[num]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr, 'x');
	return (count);
}
