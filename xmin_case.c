/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmin_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:07:16 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/04 20:35:19 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	calc_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	xmin_case(unsigned int hexa)
{
	int					i;

	i = 0;
	if (hexa == 0)
		i += write(1, "0", 1);
	else
	{
		i = calc_hexa_len(hexa);
		ft_putuhexa_fd(hexa, 1, 0);
	}
	return (i);
}
