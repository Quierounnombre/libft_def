/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:21:38 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/19 12:42:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;
	size_t	j;

	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	if (dstsize != 0 && i < (dstsize - 1))
	{
		while (i < (dstsize - 1) && src[j] != '\0')
		{
			dst[i++] = src[j++];
		}
		dst[i] = '\0';
	}
	if (len_dst > dstsize)
		return (dstsize + len_src);
	return (len_dst + len_src);
}
