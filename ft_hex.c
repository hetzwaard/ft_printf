/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/27 16:20:46 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/27 16:20:46 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(va_list arg, const char c)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_putpos(hex, c));
}
