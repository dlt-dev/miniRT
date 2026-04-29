/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:05:00 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 08:05:05 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
