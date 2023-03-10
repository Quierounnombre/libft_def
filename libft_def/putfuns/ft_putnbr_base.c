/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:00:34 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/05 18:42:56 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	basecheck(char *base, int base_size)
{
	char	c;
	int		i;
	int		j;

	if (base_size <= 1)
		return (0);
	i = 0;
	while (i < base_size)
	{
		c = base[i];
		if (c == '+' || c == '-')
			return (0);
		j = i + 1;
		while (j < base_size)
		{
			if (c == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(long int nbr, char *base)
{
	int		base_size;

	base_size = ft_strlen(base);
	if (basecheck(base, base_size) == 1)
	{
		if (nbr == -2147483648)
		{
			ft_putnbr_base((nbr / base_size), base);
			ft_putnbr_base((nbr % base_size), base);
		}
		else if (nbr < 0)
		{
			nbr = nbr * -1;
			write(1, "-", 1);
			ft_putnbr_base(nbr, base);
		}
		else if (nbr <= (base_size - 1))
			write(1, &base[nbr], 1);
		else
		{
			ft_putnbr_base((nbr / base_size), base);
			write(1, &base[nbr % base_size], 1);
		}
	}
}
