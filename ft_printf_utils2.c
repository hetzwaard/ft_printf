/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 11:39:14 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/11/11 11:39:14 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_unsigned(unsigned int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (nb >= 10)
		i += ft_unsigned(nb / 10);
	n = nb % 10 + 48;
	i += write(1, &n, 1);
	return (i);
}
