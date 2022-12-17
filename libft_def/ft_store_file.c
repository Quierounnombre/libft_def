/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:26:09 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/17 14:42:50 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	ft_store_line(char **dst, char *s)
{
	char	*temp;

	if (!(*dst))
		*dst = s;
	else
	{
		temp = ft_strjoin((*dst), s);
		if (!temp)
			return (false);
		*dst = temp;
		free(temp);
	}
	free(s);
	return (true);
}

t_bool	ft_store_file(int fd, char **target)
{
	char	*s;
	char	*dst;

	s = ft_get_next_line(fd);
	if (!s)
		return (false);
	while (s)
	{
		if (s && ft_store_line(&dst, s))
		{
			s = ft_get_next_line(fd);
		}
		else
		{
			free(*target);
			return (false);
		}
	}
	close(fd);
	return (true);
}
