/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/27 16:19:37 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/27 16:19:37 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(va_list arg)
{
	unsigned long int	p;

	p = va_arg(arg, unsigned long int);
	if (!p || p == 0)
		return (ft_putstr("(nil)"));
	return (write(1, "0x", 2) + ft_putpos(p, 'p'));
}
