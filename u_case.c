/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:59:54 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/05 18:32:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	u_case(int c)
{
	unsigned int	uc;
	int				i;

	if (c < 0)
	{
		i = 0;
		uc = UINT_MAX + (c + 1);
		ft_putunbr_fd(uc, 1);
		while (uc > 0)
		{
			uc /= 10;
			i++;
		}
		return (i);
	}
	return (di_case(c));
}
