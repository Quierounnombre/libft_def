/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemsFuns2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:13:12 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/18 14:04:47 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s1;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	s1 = malloc(count * size);
	if (s1 == NULL)
		return (NULL);
	ft_bzero(s1, count * size);
	return (s1);
}
