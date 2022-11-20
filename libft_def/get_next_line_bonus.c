/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:32:34 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/21 17:37:07 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_main(char *buffer, int fd)
{
	char	*line;
	char	*local_buffer;
	int		isend;

	isend = 1;
	local_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!local_buffer)
		return (NULL);
	while (isend > 0)
	{
		isend = read(fd, local_buffer, BUFFER_SIZE);
		if (isend == -1)
		{
			free(local_buffer);
			return (NULL);
		}
		local_buffer[isend] = '\0';
		line = ft_strjoin(buffer, local_buffer);
		free(buffer);
		buffer = line;
		if (ft_strchr(local_buffer, '\n'))
			break ;
	}
	free (local_buffer);
	return (buffer);
}

char	*cut_line(char	*buffer)
{
	char	*final;
	int		i;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	final = (char *)malloc (sizeof(char) * (i + 2));
	if (!final)
		return (NULL);
	ft_strlcpy(final, buffer, (i + 2));
	return (final);
}

char	*take_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rest = (char *) malloc((ft_strlen(buffer) + 1 - i) * sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	free(buffer);
	return (rest);
}

char	*ft_get_next_line(int fd)
{
	static char	*buffer[FD_SETSIZE];
	char		*reline;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = (char *)malloc(sizeof(char));
		*buffer[fd] = '\0';
	}
	buffer[fd] = read_main(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	reline = cut_line(buffer[fd]);
	buffer[fd] = take_rest(buffer[fd]);
	return (reline);
}
