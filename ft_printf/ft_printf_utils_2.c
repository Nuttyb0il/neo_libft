/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:57:45 by yfoucade          #+#    #+#             */
/*   Updated: 2022/03/01 22:30:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbrbase(unsigned long long nbr, char base, char lower)
{
	size_t	res;
	char	*base_str;
	char	to_print;
	char	lflag;

	base_str = "0123456789ABCDEF";
	res = 0;
	if (nbr >= (unsigned long)base)
		res += ft_putnbrbase(nbr / base, base, lower);
	to_print = base_str[nbr % base];
	lflag = 'A' <= to_print;
	lflag *= to_print <= 'F';
	res += ft_putchar(to_print + 32 * lower * lflag);
	return (res);
}

size_t	ft_putdec(long long nbr)
{
	size_t	res;

	res = 0;
	if (nbr < 0)
	{
		res += write(1, "-", 1);
		nbr = -nbr;
	}
	return (res + ft_putnbrbase(nbr, 10, 0));
}

size_t	ft_puthex(unsigned long nbr)
{
	int	i;
	
	i = write(1, "0x", 2);
	return (i + ft_putnbrbase(nbr, 16, 1));
}

size_t	ft_putcsp(char converter, va_list ap)
{
	size_t	res;

	res = 0;
	if (converter == 'c')
		res += ft_putchar(va_arg(ap, int));
	if (converter == 's')
		res += ft_putstr(va_arg(ap, char *));
	if (converter == 'p')
		res += ft_puthex(va_arg(ap, long));
	return (res);
}
