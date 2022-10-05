/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:09:04 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/19 13:47:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_aux(int c, char *s, int len, int neg)
{
	int	temp;

	len--;
	s[len] = '\0';
	temp = c * neg;
	if (temp == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	while (temp > 0)
	{
		s[--len] = (temp % 10) + '0';
		temp = temp / 10;
	}
	if (neg == -1)
		s[0] = '-';
	return (s);
}

static int	ft_calclen(int temp)
{
	int	len;

	len = 0;
	if (temp == 0)
		return (1);
	while (temp)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int c)
{
	char	*s;
	int		temp;
	int		len;
	int		neg;

	len = 0;
	if (c <= -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 1;
	if (c < 0)
	{
		neg = -1;
		len++;
	}
	temp = c;
	len = ft_calclen(temp) + len;
	if (c == 0)
		len = 1;
	s = (char *)malloc ((len + 1) * sizeof(char));
	if (s)
	{
		return (ft_itoa_aux(c, s, len + 1, neg));
	}
	return (NULL);
}
