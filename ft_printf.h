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

int		format_char(va_list args);
int		format_integer(va_list args);
int		format_string(va_list args);

char	*ft_itoa(int n);

size_t	ft_strlen(const char *s);

#endif
