/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:35:21 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/18 16:35:22 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (0);
}

int	ft_conversions(char c, va_list argp)
{
	if (c == 'c')
		ft_putchar(va_arg(argp, int));
	if (c == 's')
		ft_putstr(va_arg(argp, char *));
	if (c == 'x')
		ft_convertdectohexa(va_arg(argp, char *));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;

	va_start(argp, format);
	while (*format)
	{
		while (*format != '%' && *format)
		{
			ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar('%');
			else
				ft_conversions(*format, argp);
			format++;
		}
	}
	va_end(argp);
	return (0);
}

int	ft_convertdectohexa(int nb)
{
	if (nb >= 16)
	{
		ft_convertdectohexa(nb / 16);
		ft_convertdectohexa(nb % 16);
	}
	else
		ft_putchar(BASE16[nb]);
	return (nb);
}

// int main(void)
// {
// 	// char *base ="0123456789abcdef";

// 	// 11 / 16  

// 	// printf("%c, %s, %p, ");

// 	// ft_printf("bon%/  %c ecr%sire %c%c%c a\n", 'a', "bonj", 'b', 'c', 'd');
// 	printf("bon%/  %c ecr%sire %c%c%c a\n", 'a', "bonj", 'b', 'c', 'd');
// 	// printf("%d", ox);
// 	ft_convertdectohexa(1516);
// }