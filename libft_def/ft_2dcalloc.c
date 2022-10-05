/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dcalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:34:59 by marvin            #+#    #+#             */
/*   Updated: 2022/09/27 20:34:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_2dcalloc(size_t size, size_t datatype)
{
	void	**arr;
	size_t	i;

	i = 0;
	arr = (void *)ft_calloc(size + 1, datatype);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = ft_calloc(1, datatype);
		i++;
	}
	return (arr);
}
