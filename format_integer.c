/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_integer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/26 23:35:58 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/26 23:35:58 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_integer(va_list args)
{
	int		num;
	int		len;
	char	*str;

	num = va_arg(args, int);
	str = ft_itoa(num);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
