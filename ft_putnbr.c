/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/27 14:28:32 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/27 14:28:32 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;
	int	n;

	i = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
	}
	n = nb % 10 + 48;
	i += write(1, &n, 1);
	return (i);
}
