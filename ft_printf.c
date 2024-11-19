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
int	ft_convert10to16(int nb, char c)
{
	if (nb >= 16)
	{
		ft_convert10to16(nb / 16, c);
		ft_convert10to16(nb % 16, c);
	}
	else if ((nb < 16 && c == 'x') || (c == 'X' && nb < 10))
		ft_putchar(BASE16[nb]);
	else if (nb > 9 && nb < 16 && c == 'X')
		ft_putchar(BASE16[nb] - 32);
	return (0);
}

int	ft_putnbr(long int n) //long int meme valeur max que unsigned int
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (0);
}

int	ft_conversions(char c, va_list argp)
{
	if (c == '%')
		ft_putchar('%');
	else if (c == 'c')
		ft_putchar(va_arg(argp, int));
	else if (c == 's')
		ft_putstr(va_arg(argp, char *));
	else if (c == 'x' || c == 'X')
		ft_convert10to16(va_arg(argp, int), c);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(argp, int));
	else if (c == 'u')
		ft_putnbr(va_arg(argp, unsigned int));
	return (0);	
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;

	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_conversions(*format, argp);
		}
		else 
			ft_putchar(*format);
		format++;
	}
	va_end(argp);
	return (0);
}

int main(void)
{
	int a = -2147483648;
	
	ft_printf("|test pourcemtage=%%|\n");
	printf("|test pourcemtage=%%|\n\n");

	ft_printf("|test char a=%c|\n", 'a');
	printf("|test char a=%c|\n\n", 'a');

	ft_printf("|test str bonjour=%s|\n", "bonjour");
	printf("|test str bonjour=%s|\n\n", "bonjour");

	ft_printf("|test str vide=%s|\n", "");
	printf("|test str vide=%s|\n\n", "");

	ft_printf("|test hexa lower=%x|\n", 1516);
	printf("|test hexa lower=%x|\n\n", 1516);

	ft_printf("|test hexa lower=%X|\n", 1516);
	printf("|test hexa lower=%X|\n\n", 1516);

	ft_printf("|test decimal 1516=%d|\n", a);
	printf("|test decimal 1516=%d|\n\n", a);

	ft_printf("|test integer 1516=%i|\n", a);
	printf("|test integer 1516=%i|\n\n", a);

	ft_printf("|test unsigned integer 1516=%u|\n", 2147483647);
	printf("|test unigned integer 1516=%u|\n\n", 2147483647);

	printf("%d", printf("|test integer 1516=%u|\n\n", 2147483647));

	printf("moi %d", ft_printf("|test pourcemtage=%%|\n"));
	printf("printf%d", printf("|test pourcemtage=%%|\n\n"));


}