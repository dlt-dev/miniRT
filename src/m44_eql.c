/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_eql.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:16:35 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 10:16:43 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

bool	m44_eql(const t_m44 *m1, const t_m44 *m2)
{
	int	i;

	if (!m1 || !m2)
		return (false);
	i = 0;
	while (i < M44_SIZE * M44_SIZE)
	{
		if (!deql((*m1)[i], (*m2)[i]))
			return (false);
		i++;
	}
	return (true);
}
