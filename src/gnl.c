/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:06:39 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 12:51:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static void	*ft_extract_line(char **stock)
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

static int	ft_read_and_append(int fd, char **stock, char *buffer)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = read(fd, buffer, GNL_BUFFER_SIZE);
	if (bytes > 0)
	{
		buffer[bytes] = '\0';
		tmp = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = tmp;
	}
	return (bytes);
}

char	*gnl(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;
	ssize_t		bytes;

	if (fd == GNL_CLEAR)
		return (free(stock), NULL);
	bytes = 1;
	buffer = (char *)malloc(GNL_BUFFER_SIZE + 1);
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
