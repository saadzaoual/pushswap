/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:51:27 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/25 15:46:51 by szaoual          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ft_printf.h"

int	ft_flags(char format, va_list args)
{
	int	counter;

	counter = 0;
	if (format == 's')
		counter += ft_putstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		counter += ft_putnbr(va_arg(args, int));
	if (format == 'c')
		counter += ft_putchar(va_arg(args, int));
	if (format == 'x' || format == 'X')
		counter += ft_puthexa(va_arg(args, unsigned int), format);
	if (format == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_puthexa(va_arg(args, unsigned long), 'x');
	}
	if (format == 'u')
		counter += ft_putunbr(va_arg(args, unsigned int));
	if (format == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	char	*p;
	int		cont;

	if (!format || write(1, 0, 0) == -1)
		return (-1);
	va_start(list, format);
	cont = 0;
	p = (char *) format;
	while (*p)
	{
		if (*p == '%')
		{
			if (*(p + 1) == '\0')
				return (cont);
			cont += ft_flags(*(++p), list);
		} 
		else
			cont += ft_putchar(*p);
		p++;
	}
	va_end(list);
	return (cont);
}
