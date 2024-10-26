/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_string.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/26 23:40:53 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/26 23:40:53 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	format_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
