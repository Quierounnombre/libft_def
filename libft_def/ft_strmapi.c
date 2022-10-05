/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:48:02 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/18 18:57:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;
	int		size;

	i = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s) + 1;
	s2 = malloc(size * sizeof(char));
	if (!s2)
		return (NULL);
	while (*s != '\0')
	{
		s2[i] = f(i, *s);
		s++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
