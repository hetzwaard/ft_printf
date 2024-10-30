/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/26 19:37:34 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/30 19:15:23 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list arg, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(arg, int));
	if (format == 's')
		count = ft_putstr(va_arg(arg, char *));
	if (format == 'p')
		count = ft_putptr(arg);
	if (format == 'd' || format == 'i')
		count = ft_putnbr(va_arg(arg, int));
	if (format == 'u')
		count = ft_unsigned(va_arg(arg, unsigned int));
	if (format == 'x' || format == 'X')
		count = ft_hex(arg, format);
	if (format == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(args, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			if (format[i])
				count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
