/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_vtrf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:49:35 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 15:09:25 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transformations.h"

// The orientation matrix will be shaped as :
// |  left.x     left.y     left.z     0 |
// | true_up.x  true_up.y  true_up.z   0 |
// | -forward.x -forward.y -forward.z  0 |
// |     0          0          0       1 |
void	m44_orientate(const t_v4 *left, const t_v4 *true_up, const t_v4 *forward, t_m44 *res)
{
	(*res)[0 * 4 + 0] = left->x;
	(*res)[0 * 4 + 1] = left->y;
	(*res)[0 * 4 + 2] = left->z;
	(*res)[0 * 4 + 3] = 0.0;
	(*res)[1 * 4 + 0] = true_up->x;
	(*res)[1 * 4 + 1] = true_up->y;
	(*res)[1 * 4 + 2] = true_up->z;
	(*res)[1 * 4 + 3] = 0.0;
	(*res)[2 * 4 + 0] = -forward->x;
	(*res)[2 * 4 + 1] = -forward->y;
	(*res)[2 * 4 + 2] = -forward->z;
	(*res)[2 * 4 + 3] = 0.0;
	(*res)[3 * 4 + 0] = 0.0;
	(*res)[3 * 4 + 1] = 0.0;
	(*res)[3 * 4 + 2] = 0.0;
	(*res)[3 * 4 + 3] = 1.0;
}

int	m44_vtrf(const t_pt *from, const t_pt *to, const t_v4 *up, t_m44 *res)
{
	t_m44_vtrf_var	v;

	v.forward = v4_uni(v4_sub(*to, *from));
	v.upn = v4_uni(*up);
	v.left = v4_xpr(v.forward, v.upn);
	v.true_up = v4_xpr(v.left, v.forward);
	m44_trl(-from->x, -from->y, -from->z, &(v.trl));
	m44_orientate(&(v.left), &(v.true_up), &(v.forward), &(v.orientation));
	m44_prd(&(v.orientation), &(v.trl), res);
	return (0);
}
