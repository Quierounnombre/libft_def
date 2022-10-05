/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:36:57 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/04 20:06:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	cases(const char *s, va_list largv)
{
	s++;
	if (*s == 'c')
		return (c_case(va_arg(largv, int)));
	else if (*s == 's')
		return (s_case(va_arg(largv, char *)));
	else if (*s == 'p')
		return (p_case(va_arg(largv, unsigned long long)));
	else if (*s == 'd' || *s == 'i')
		return (di_case(va_arg(largv, int)));
	else if (*s == 'x')
		return (xmin_case(va_arg(largv, int)));
	else if (*s == 'X')
		return (xmax_case(va_arg(largv, int)));
	else if (*s == 'u')
		return (u_case(va_arg(largv, int)));
	else if (*s == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
