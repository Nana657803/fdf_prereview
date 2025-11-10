/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndobashi <ndobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:02:01 by ndobashi          #+#    #+#             */
/*   Updated: 2025/05/03 12:14:21 by ndobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* メイン関数 */
int	ft_printf(const char *format, ...);

/* 文字と文字列の処理関数 */
int	ft_putchar(char c);
int	ft_putstr(char *str);

/* 数値処理関数 */
int	ft_putnbr(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_puthex(unsigned long num, char format);
int	ft_putptr(void *ptr);

/* フォーマット指定子処理関数 */
int	ft_format_handler(va_list args, char format);

#endif
