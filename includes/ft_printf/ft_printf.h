/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:03:07 by skoudad           #+#    #+#             */
/*   Updated: 2024/12/21 16:16:38 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_pointer(void *ptr);
int		print_int(int n);
int		print_unsigned(unsigned int n);
int		print_hex(uintptr_t n, char format);

#endif
