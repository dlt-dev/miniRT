/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:24:23 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:06:27 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	mat_sub(const t_mat *m1, const t_mat *m2, t_mat *res)
{
	unsigned int	i;

	i = 0;
	if (!m1 || !m2 || !res || !m1->m || !m2->m)
		return (-1);
	if (m1->r != m2->r || m1->c != m2->c)
		return (-1);
	if (!mat_set(m1, res))
		return (-1);
	while (i < m1->r * m1->c)
	{
		res->m[i] = m1->m[i] - m2->m[i];
		i++;
	}
	return (0);
}
