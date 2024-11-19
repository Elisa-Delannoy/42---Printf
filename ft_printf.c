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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	// va_list	argp;

	// va_start(argp, format);
	int	i;

	i = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
			i++;
		ft_conversions(format[i]);
	}
	return (0);
	// va_end(argp);
}

int	ft_conversions(char c)
{
	if (c == '%')
		ft_putchar(c);
		
}





// void	ft_convertdectohexa(int nb)
// {

// 	if (nb >= 16)
// 	{
// 		nb = ft_convertdectohexa(nb / 16);
// 		nb = ft_putchar(nb % 16);
// 	}
// 	else
// 	{
// 		// if(nb >= 10 && nb <= 15)
// 		// 	ft_putchar(nb +);
// 		ft_putchar(nb);
// 	}
// }




#include <stdio.h>
int main(void)
{
	// char *base ="0123456789abcdef";

	// 11 / 16  

	// printf("%c, %s, %p, ");
	printf("bon%%jour");
}