/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:22:19 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/18 17:06:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, unsigned int c)
{
	while (*src != '\0')
	{
		if (*src == (unsigned char)c)
		{
			return ((char *)src);
		}
		src++;
	}
	if (c == '\0')
		return ((char *)src);
	return (NULL);
}
