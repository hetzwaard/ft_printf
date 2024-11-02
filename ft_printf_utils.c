/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/27 22:03:07 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/11/02 11:13:00 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(va_list arg, const char c)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_puthex(hex, c));
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	i;
	int	n;

	i = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
	}
	n = nb % 10 + 48;
	i += write(1, &n, 1);
	return (i);
}

int	ft_puthex(unsigned long int arg, const char c)
{
	int	i;
	int	len;

	len = 0;
	i = arg % 16;
	if (arg >= 16)
		len += ft_puthex(arg / 16, c);
	if (i < 10)
		i += 48;
	else
	{
		if (c == 'X')
			i += 55;
		else
			i += 87;
	}
	len += write(1, &i, 1);
	return (len);
}

int	ft_putptr(va_list arg)
{
	unsigned long int	p;

	p = va_arg(arg, unsigned long int);
	if (p == 0)
		return (ft_putstr("(nil)"));
	return (write(1, "0x", 2) + ft_puthex(p, 'p'));
}
