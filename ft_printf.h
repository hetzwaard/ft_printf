/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/26 19:43:06 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/26 19:43:06 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_putstr(const char *s);
int		ft_putptr(va_list arg);

int		ft_hexadecimal(va_list arg, const char c);
int		ft_putpos(unsigned long int arg, const char c);
int		ft_putunsigned(unsigned int nb);

char	*ft_itoa(int n);

size_t	ft_strlen(const char *s);

#endif
