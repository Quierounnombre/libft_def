/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:29:34 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/19 12:44:12 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_first(const char *s1, char const *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	get_last(const char *s1, char const *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = get_first(s1, set);
	j = get_last(s1, set);
	if (i >= j)
		return (ft_strdup(""));
	s = (char *)malloc (sizeof(char) * (j - i + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + i, j - i + 1);
	return (s);
}
