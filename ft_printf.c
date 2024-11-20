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

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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
	return (i);
}

int	ft_convert10to16(long int nb, char c, int j)
{
	if (nb >= 16)
	{
		j = ft_convert10to16(nb / 16, c, j);
		j = ft_convert10to16(nb % 16, c, j);
	}
	else if ((nb < 16 && c == 'x') || (c == 'X' && nb < 10) || (nb < 16 && c == 'p'))
		j = j + ft_putchar(BASE16[nb]);
	else if (nb > 9 && nb < 16 && c == 'X')
		j = j + ft_putchar(BASE16[nb] - 32);
	printf("\nj hexa =%d\n", j);
	return (j);
}

int	ft_putnbr(long int n) //long int meme valeur max que unsigned int
{
	long int	nb;
	int			i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		i++;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
		i++;
	}
	return (i);
}	

int	ft_conversions(char c, va_list argp)
{
	int	i;
	
	i = 0;
	// if (c == '%')
	// 	i = ft_putchar('%');
	if (c == 'c')
		i = ft_putchar(va_arg(argp, int));
	else if (c == 's')
		i = ft_putstr(va_arg(argp, char *));
	else if (c == 'x' || c == 'X')
		i = ft_convert10to16(va_arg(argp, int), c, 0);
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(argp, long int));
	else if (c == 'u')
		i = ft_putnbr(va_arg(argp, unsigned int));
	else if (c == 'p')
	{	 
		ft_putchar('0');
		ft_putchar('x');
		i = ft_convert10to16(va_arg(argp, unsigned long int), c, 0) + 3; /*2*putchar + p*/
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		i;

	i = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				i = i + ft_putchar('%');
			else
				i =  i + ft_conversions(*format, argp);
		}
		else
			i = i + ft_putchar(*format);
		printf("i = %d\n", i);
		format++;
	}
	va_end(argp);
	return (i);
}

int main(void)
{
	int a = 15254;

	// ft_printf("|test pourcemtage=%%|\n");
	// printf("|test pourcemtage=%%|\n\n");
	// printf("%d\n", ft_printf("|test pourcentage=%%|\n"));
	// printf("%d\n\n", printf("|test pourcentage=%%|\n"));

	// // ft_printf("|test char a=%c|\n", 'a');
	// // printf("|test char a=%c|\n\n", 'a');
	// printf("%d\n", ft_printf("|test char a=%c|\n", 'a'));
	// printf("%d\n\n", printf("|test char a=%c|\n", 'a'));

	// ft_printf("|test str bonjour=%s|\n", "bonjour");
	// printf("|test str bonjour=%s|\n\n", "bonjour");
	// printf("%d\n", ft_printf("|test str bonjour=%s|\n", "bonjour"));
	// printf("%d\n\n", printf("|test str bonjour=%s|\n", "bonjour"));


	// ft_printf("|test str vide=%s|\n", "");
	// printf("|test str vide=%s|\n\n", "");
	// printf("%d\n", ft_printf("|test str vide=%s|\n", ""));
	// printf("%d\n\n", printf("|test str vide=%s|\n", ""));

	// ft_printf("|test hexa lower=%x|\n", a);
	// printf("|test hexa lower=%x|\n\n", a);
	printf("%d\n", ft_printf("|test hexa lower=%x|\n", a));
	printf("%d\n\n", printf("|test hexa lower=%x|\n", a));

	// ft_printf("|test hexa upper=%X|\n", a);
	// printf("|test hexa upper=%X|\n\n", a);
	printf("%d\n", ft_printf("|test hexa upper=%X|\n", a));
	printf("%d\n\n", printf("|test hexa upper=%X|\n", a));

	// // ft_printf("|test decimal =%d|\n", a);
	// // printf("|test decimal =%d|\n\n", a);
	// printf("%d\n", ft_printf("|test decimal =%d|\n", a));
	// printf("%d\n\n", printf("|test decimal =%d|\n", a));

	// // ft_printf("|test integer =%i|\n", a);
	// // printf("|test integer =%i|\n\n", a);
	// printf("%d\n", ft_printf("|test integer =%i|\n", a));
	// printf("%d\n\n", printf("|test integer =%i|\n", a));

	// // ft_printf("|test unsigned integer =%u|\n", a);
	// // printf("|test unsigned integer =%u|\n\n", a);
	// printf("%d\n", ft_printf("|test unsigned integer =%u|\n", a));
	// printf("%d\n\n", printf("|test unsigned integer =%u|\n", a));

	// ft_printf("|test adresse =%p|\n", "123456 bonjour");
	// printf("|test adresse =%p|\n\n", "123456 bonjour");
	// printf("%d\n", ft_printf("|test adresse =%p|\n", "123456 bonjour"));
	// printf("%d\n", printf("|test adresse =%p|\n", "123456 bonjour"));
}