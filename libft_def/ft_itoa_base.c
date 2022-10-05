/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:25:28 by vicgarci          #+#    #+#             */
/*   Updated: 2022/10/05 17:20:46 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_aux(int c, char *s, int len, char *base)
{
	int	temp;
	int	neg;
	int	baselen;

	len--;
	s[len] = '\0';
	neg = 1;
	if (c < 0)
		neg = -1;
	temp = c * neg;
	if (temp == 0)
	{
		s[0] = base[0];
		s[1] = '\0';
	}
	baselen = ft_strlen(base);
	while (temp > 0)
	{
		s[--len] = base[(temp % baselen)];
		temp = temp / baselen;
	}
	if (neg == -1)
		s[0] = '-';
	return (s);
}

static int	ft_calclen(int temp, int baselen)
{
	int	len;

	len = 0;
	if (temp == 0)
		return (1);
	while (temp)
	{
		temp /= baselen;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long long c, char *base)
{
	char	*s;
	int		temp;
	int		len;
	int		baselen;
	int		neg;

	len = 0;
	neg = 1;
	baselen = ft_strlen(base);
	if (c < 0)
	{
		neg = -1;
		len++;
	}
	temp = c;
	len = ft_calclen(temp, baselen) + len;
	if (c == 0)
		len = 1;
	s = (char *)malloc ((len + 1) * sizeof(char));
	if (s)
	{
		return (ft_itoa_aux(c, s, len + 1, base));
	}
	return (NULL);
}
