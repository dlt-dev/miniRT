/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_inv_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:19:45 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 14:36:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

// Computes the Inverse of a Pure Rotation Matrix
// A Pure rotation matrix is shaped as :
//		[	Rxyz    0]
//		[   3x3		0]
//		[			0]
//		[0	0  0    1]
// Where Rxyz is a 3x3 roation matrix
// The Inverse of a pure rotation matrix is:
//		[	RTxyz   0]
//		[   3x3		0]
//		[			0]
//		[0	0  0    1]
// Where RTxyz is the transpose of the 3x3 matrix Rxyz.

int	m44_inv_rot(const t_m44 *m1, t_m44 *res)
{
	if (!m1 || !res)
		return (-1);
	if (m44_trp(m1, res) != 0)
		return (-1);
	return (0);
}
