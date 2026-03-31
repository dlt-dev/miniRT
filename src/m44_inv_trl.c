/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_inv_trl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:15:46 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 14:36:06 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

// Computes the Inverse of a pure translation matrix.
// A Pure translation matrix shaped as :
//		[1 0 0 Tx]
//		[0 1 0 Ty]
//		[0 0 1 Tz]
//		[0 0 0 1 ]
// Its Inverse is :
//		[1 0 0 -Tx]
//		[0 1 0 -Ty]
//		[0 0 1 -Tz]
//		[0 0 0  1 ]

int	m44_inv_trl(const t_m44 *m1, t_m44 *res)
{
	if (!m1 || !res)
		return (-1);
	if (m44_cpy(m1, res) != 0)
		return (-1);
	(*res)[3] = -(*m1)[3];
	(*res)[7] = -(*m1)[7];
	(*res)[11] = -(*m1)[11];
	return (0);
}
