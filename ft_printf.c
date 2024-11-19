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

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_conversions(char c, va_list argp)
{
	if (c == 'c')
		ft_putchar(va_arg(argp, int));
	if (c == 's')
		ft_putstr(va_arg(argp, char *));
	
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
	return (0);
	va_end(argp);
}


// void	ft_convertdectohexa(int nb)
// {

// 	if (nb >= 16)
// 	{
// 		nb = ft_convertdectohexa(nb / 16);
// 		nb = ft_putchar(nb % 16);
// 	}
// 	else
// 		ft_putchar(nb);
// }


#include <stdio.h>
int main(void)
{
	// char *base ="0123456789abcdef";

	// 11 / 16  

	// printf("%c, %s, %p, ");

	ft_printf("bonjour%%pourent  /  %c ecr%sire %c%c%c a", 'a', "bonj", 'b', 'c', 'd');

	
}