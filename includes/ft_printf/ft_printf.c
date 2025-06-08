/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:19:48 by skoudad           #+#    #+#             */
/*   Updated: 2025/01/15 20:13:59 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_formats(va_list args, char format)
{
	if (format == 'c')
		return (print_char(va_arg(args, int)));
	else if (format == 's')
		return (print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_formats(args, *format);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	int count;
	count = ft_printf("hellooo %s\n", "sam");
	ft_printf("hellooo %s %d\n", "sam", count);
	count = printf("hellooo %s\n", "sam");
	printf("hellooo %s %d\n", "sam", count);
	return 0;
}*/
