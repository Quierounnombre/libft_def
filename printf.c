/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:56:28 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/26 20:29:20 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *s, ...)
{
	long int	printlen;
	va_list		largv;

	va_start(largv, s);
	printlen = 0;
	while (*s != '\0')
	{
		if (*s == '%' && *(s + 1) != '\0')
		{
			printlen += cases(s, largv);
			s++;
		}
		else
		{
			write(1, s, 1);
			printlen++;
		}
		s++;
	}
	va_end(largv);
	return (printlen);
}
