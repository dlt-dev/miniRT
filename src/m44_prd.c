/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:18:05 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 10:22:33 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	m44_prd(const t_m44 *m1, const t_m44 *m2, t_m44 *res)
{
	int		i;
	int		j;
	int		k;

	if (!m1 || !m2 || !res)
		return (-1);
	i = 0;
	while (i < M44_SIZE)
	{
		j = 0;
		while (j < M44_SIZE)
		{
			(*res)[i * M44_SIZE + j] = 0.0;
			k = 0;
			while (k < M44_SIZE)
			{
				(*res)[i * M44_SIZE + j] += (*m1)[i * M44_SIZE + k]
					* (*m2)[k * M44_SIZE + j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
