/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/26 23:34:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/26 23:34:12 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}
