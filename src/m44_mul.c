/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:17:51 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 10:17:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	m44_mul(const t_m44 *m1, double scalar, t_m44 *res)
{
	int	i;

	if (!m1 || !res)
		return (-1);
	i = 0;
	while (i < M44_SIZE * M44_SIZE)
	{
		(*res)[i] = (*m1)[i] * scalar;
		i++;
	}
	return (0);
}
