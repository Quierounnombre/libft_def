/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:26:09 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/17 13:29:45 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_store_file(int fd, char **target)
{
	char	*s;
	char	*temp;

	s = ft_get_next_line(fd);
	if (!s)
		return (false);
	while (s)
	{
		if (s)
		{
			temp = ft_strjoin(*target, s);
			*target = temp;
			free(s);
			if (!(*target))
				return (false);
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
