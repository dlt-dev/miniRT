/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_idm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:35:03 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:06:48 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	mat_idm(const t_mat *m1, t_mat *res)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!m1 || !res)
		return (-1);
	if (m1->r != m1->c)
		return (-1);
	if (!mat_set(m1, res))
		return (-1);
	while (i < res->r)
	{
		while (j < res->c)
		{
			if (i == j)
				res->m[i * res->c + j] = 1.0;
			else
				res->m[i * res->c + j] = 0.0;
			j++;
		}
		i++;
	}
	return (0);
}
