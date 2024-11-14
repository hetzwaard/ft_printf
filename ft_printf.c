/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 11:31:21 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/11/11 11:31:21 by mahkilic      ########   odam.nl         */
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

//int main(void)
//{
//	ft_printf("hello my name is %s and I am %d years old\n", "Mahmut", 19);
//	printf("hello my name is %s and I am %d years old\n", "Mahmut", 19);
//}

/*gcc ft_printf.c ft_printf_utils.c ft_printf_utils2.c -o ft_printf
&& ./ft_printf && rm -rf ft_printf
*/