/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:09:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/01/30 11:04:12 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	byte;
	char	*addr;
	size_t	i;

	addr = s;
	byte = c;
	i = 0;
	while (i < n)
	{
		addr[i] = byte;
		i++;
	}
	return (s);
}
