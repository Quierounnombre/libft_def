/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:26:09 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/17 19:02:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**load(char **s, char *s2)
{
	int		i;
	char	**new;

	i = 0;
	while ((s[i]) != NULL)
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	if (new)
	{
		i = 0;
		while ((s[i]) != NULL)
		{
			new[i] = s[i];
			i++;
		}
		new[i] = s2;
	}
	free(s);
	return (new);
}

static t_bool	free_all(char **s)
{
	int	i;

	i = 0;
	while ((s[i]) != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (false);
}

static void	store(char **dst, char **s)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][j])
		{
			(*dst)[j] = s[i][j];
			j++;
		}
		free(s[i]);
	}
	i++;
	(*dst)[i] = '\0';
	free(s);
}

static char	*convert(char **s)
{
	int		i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	while ((s[i]) != NULL)
	{
		len += strlen(s[i]);
		i++;
	}
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst)
		store(&dst, s);
	return (dst);
}

t_bool	ft_store_file(int fd, char **target)
{
	char	*s;
	char	**store;

	s = ft_get_next_line(fd);
	while (s)
	{
		store = load(store, s);
		if (!store)
			return (free_all(store));
		s = ft_get_next_line(fd);
	}
	(*target) = convert(store);
	return (true);
}

int main(void)
{
	char	*s;
	int		fd = open("./text", O_RDONLY);

	if (ft_store_file(fd, &s))
	{
		system("Leaks PRUEBAS");
		printf("%s\n", s);
	}
}
