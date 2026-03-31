/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_inv_scl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:26:53 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 14:35:34 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

// Computes the inverse of a pure scaling matrix
// A pure scaling matrix is shaped as :
// 		[Sx 0  0  0]
// 		[0  Sy 0  0]
// 		[0  0  Sz 0]
// 		[0  0  0  1]
// Its inverse is :
// 		[1/Sx  0    0   0]
// 		[0    1/Sy  0   0]
// 		[0     0   1/Sz 0]
// 		[0     0    0   1]

int	m44_inv_scl(const t_m44 *m1, t_m44 *res)
{
	if (!m1 || !res)
		return (-1);
	if ((*m1)[0] == 0 || (*m1)[5] == 0 || (*m1)[10] == 0)
		return (-1);
	if (m44_zro(res) != 0)
		return (-1);
	(*res)[0] = 1.0 / (*m1)[0];
	(*res)[5] = 1.0 / (*m1)[5];
	(*res)[10] = 1.0 / (*m1)[10];
	(*res)[15] = 1.0;
	return (0);
}
