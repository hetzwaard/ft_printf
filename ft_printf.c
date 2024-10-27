/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/26 19:37:34 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/26 19:37:34 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list arg, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(arg, int));
	if (format == 's')
		len = ft_putstr(va_arg(arg, char *));
	if (format == 'p')
		len = ft_putptr(arg);
	if (format == 'd' || format == 'i')
		len = ft_putnbr(va_arg(arg, int));
	if (format == 'u')
		len = ft_putunsigned(va_arg(arg, unsigned int));
	if (format == 'x' || format == 'X')
		len = ft_hexadecimal(arg, format);
	if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_format(args, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			if (format[i])
				len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
