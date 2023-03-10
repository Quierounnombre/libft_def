/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:51:07 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/19 12:41:32 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*aux1;
	char	*aux2;

	i = 0;
	if (!src && !dst)
		return (NULL);
	aux1 = (char *)dst;
	aux2 = (char *)src;
	if (dst > src)
	{
		while (len--)
			aux1[len] = aux2[len];
	}
	else
	{
		while (len != i)
		{
			aux1[i] = aux2[i];
			i++;
		}
	}
	return (dst);
}
