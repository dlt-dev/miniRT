/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:03:28 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 08:03:34 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
