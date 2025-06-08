/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:52:57 by skoudad           #+#    #+#             */
/*   Updated: 2024/12/17 19:56:18 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}
