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

static int	ft_format(char format, va_list args)
{
	if (format == 'd' || format == 'i')
		return (format_integer(args));
	else if (format == 'c')
		return (format_char(args));
	else if (format == 's')
		return (format_string(args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	va_start(args, format);
	i = 0;
	printed_chars = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed_chars += ft_format(format[i + 1], args);
			i++;
		}
		else
		{
			printed_chars += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (printed_chars);
}
