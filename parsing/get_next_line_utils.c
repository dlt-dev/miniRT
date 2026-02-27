/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:37:01 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/21 15:48:17 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		lenght;
	char	*m;
	int		i;

	i = 0;
	lenght = ft_strlen(s);
	m = malloc(sizeof(char) * (lenght + 1));
	if (m == 0)
		return (0);
	while (s[i])
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == source || size == 0)
		return (dest);
	while (i < size)
	{
		((char *)dest)[i] = ((char *)source)[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	maxlen;
	size_t	sublen;
	char	*sub;

	if (!s)
		return (NULL);
	maxlen = ft_strlen(s);
	if (start >= maxlen)
		return (ft_strdup(""));
	if (start + len > maxlen)
		sublen = maxlen - start;
	else
		sublen = len;
	sub = malloc(sizeof(char) * (sublen + 1));
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, sublen);
	sub[sublen] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	joinlen;
	char	*join;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	joinlen = (ft_strlen(s1) + ft_strlen(s2));
	join = malloc(sizeof(char) * (joinlen + 1));
	if (join == NULL)
		return (NULL);
	while (s1[j])
	{
		join[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	return (join);
}
