/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_eql.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:04:13 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:04:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

bool	mat_eql(const t_mat *m1, const t_mat *m2)
{
	unsigned int	i;

	i = 0;
	if (!m1 || !m2 || !m1->m || !m2->m)
		return (false);
	if (m1->r != m2->r || m1->c != m2->c)
		return (false);
	while (i < m1->r * m1->c)
	{
		if (!deql(m1->m[i], m2->m[i]))
			return (false);
		i++;
	}
	return (true);
}
