/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_trp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:04:10 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 14:06:14 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	m44_trp(const t_m44 *m1, t_m44 *res)
{
	size_t	i;
	size_t	j;

	if (!m1 || !res)
		return (-1);
	i = 0;
	while (i < M44_SIZE)
	{
		j = 0;
		while (j < M44_SIZE)
		{
			(*res)[j * M44_SIZE + i] = (*m1)[i * M44_SIZE + j];
			j++;
		}
		i++;
	}
	return (0);
}
