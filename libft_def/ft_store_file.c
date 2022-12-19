/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:26:09 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/19 13:21:53 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**load(char **s, char *s2, int size)
{
	int		i;
	char	**new;

	i = 0;
	if (s)
	{
		new = (char **)malloc(sizeof(char *) * (size + 1));
		if (new)
		{
			while (size != i)
			{
				new[i] = s[i];
				i++;
			}
			new[i] = s2;
		}
		free(s);
	}
	return (new);
}

static t_bool	free_all(char **s, int size)
{
	int	i;

	i = 0;
	while (i != size)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (false);
}

static void	store(char **dst, char **s, int size)
{
	int		i;
	int		move_correction;

	i = 0;
	move_correction = 0;
	while (i != size)
	{
		ft_memmove((*dst + move_correction), s[i], ft_strlen(s[i]));
		move_correction += ft_strlen(s[i]);
		free(s[i]);
		i++;
	}
	free(s);
}

static char	*convert(char **s, int size)
{
	int		i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	while (i != size)
	{
		len += strlen(s[i]);
		i++;
	}
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst)
		store(&dst, s, size);
	return (dst);
}

t_bool	ft_store_file(int fd, char **target)
{
	size_t	size;
	char	*s;
	char	**store;

	size = 0;
	store = (char **)malloc(sizeof(char *));
	if (!store)
		return (false);
	s = ft_get_next_line(fd);
	while (s)
	{
		store = load(store, s, size);
		if (!store)
			return (free_all(store, size));
		s = ft_get_next_line(fd);
		size++;
	}
	(*target) = convert(store, size);
	return (true);
}
