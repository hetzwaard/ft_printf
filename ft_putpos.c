/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpos.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/27 16:21:42 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/27 16:21:42 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpos(unsigned long int arg, const char c)
{
	int	i;
	int	len;

	len = 0;
	i = arg % 16;
	if (arg >= 16)
		len += ft_putpos(arg / 16, c);
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
