/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:52:35 by jdelattr          #+#    #+#             */
/*   Updated: 2026/04/29 08:05:36 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	*ft_extract_line(char **stock)
{
	char	*line;
	char	*newline;
	size_t	lenght;
	char	*tmp;

	if (*stock == NULL)
		return (NULL);
	newline = ft_strchr(*stock, '\n');
	if (newline)
		lenght = newline - *stock + 1;
	else
		lenght = ft_strlen(*stock);
	line = ft_substr(*stock, 0, lenght);
	if (!line)
		return (NULL);
	if (newline && newline[+1] != 0)
		tmp = ft_strdup(*stock + lenght);
	else
		tmp = NULL;
	free(*stock);
	*stock = tmp;
	return (line);
}

int	ft_read_and_append(int fd, char **stock, char *buffer)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes > 0)
	{
		buffer[bytes] = '\0';
		tmp = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = tmp;
	}
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;
	ssize_t		bytes;

	bytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!ft_strchr(stock, '\n') && bytes > 0)
	{
		bytes = ft_read_and_append(fd, &stock, buffer);
		if (bytes < 0)
		{
			ft_free_and_null(&stock);
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	line = ft_extract_line(&stock);
	if (!line)
		ft_free_and_null(&stock);
	return (line);
}

