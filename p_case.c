/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:13:12 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/04 20:35:12 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	calc_ptr_len(uintptr_t num)
{
	int	len;

	len = 2;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	print_ptr(uintptr_t num)
{
	if (num > 15)
	{
		print_ptr(num / 16);
		print_ptr(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd(((num - 10) + 'a'), 1);
	}
}

int	p_case(unsigned long long ptr)
{
	int		len;

	len = write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		len = calc_ptr_len(ptr);
		print_ptr(ptr);
	}
	return (len);
}
