/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:30:13 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:05:56 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	mat_mul(const t_mat *m1, double scalar, t_mat *res)
{
	unsigned int	i;

	i = 0;
	if (!m1 || !res || !m1->m)
		return (-1);
	if (!mat_set(m1, res))
		return (-1);
	while (i < m1->r * m1->c)
	{
		res->m[i] = m1->m[i] * scalar;
		i++;
	}		
	return (0);
}
