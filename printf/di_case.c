/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:13:47 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/04 20:35:07 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	di_case(int c)
{
	int	i;

	i = 0;
	ft_putnbr_fd(c, 1);
	if (c == INT_MIN)
	{
		c = INT_MIN / 10;
		i++;
	}
	if (c == 0)
		return (1);
	if (c < 0)
	{
		c = -c;
		i++;
	}
	while (c > 0)
	{
		i++;
		c /= 10;
	}
	return (i);
}