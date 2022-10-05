/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:03:12 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/18 17:14:35 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, unsigned int c)
{
	int	i;
	int	j;

	i = ft_strlen(src);
	j = i;
	while (i--)
		src++;
	while (j != -1)
	{
		if (*src == (char)c)
		{
			return ((char *)src);
		}
		src--;
		j--;
	}
	if (c == '\0')
		return ((char *)src);
	return (NULL);
}
