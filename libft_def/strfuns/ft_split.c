/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:02:41 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/19 13:19:06 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i + 1);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**ft_check(char **s, int j)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i != j)
	{
		if (!s[i])
			error++;
		i++;
	}
	i = 0;
	if (error == 2)
	{
		while (i != j)
		{
			free(s[i]);
			i++;
		}
		free (s);
		return (NULL);
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**s2;

	if (!s)
		return (NULL);
	s2 = (char **) malloc((count_words(s, c) * sizeof(char *)));
	if (!s2)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			s2[j++] = word_dup(s, index, i);
			index = -1;
		}
	}
	s2[j] = 0;
	return (ft_check(s2, count_words(s, c)));
}
