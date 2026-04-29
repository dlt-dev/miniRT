/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:02:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 08:02:57 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
