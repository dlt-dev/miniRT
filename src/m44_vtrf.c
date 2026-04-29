/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_vtrf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:49:35 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 13:59:38 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transformations.h"

// Parameters are :
// l : left
// t : true_up
// f : forward
// r : matrix in which the result will be written
// The orientation matrix will be shaped as :
// |  left.x     left.y     left.z     0 |
// | true_up.x  true_up.y  true_up.z   0 |
// | -forward.x -forward.y -forward.z  0 |
// |     0          0          0       1 |
void	m44_orientate(const t_v4 *l, const t_v4 *t, const t_v4 *f, t_m44 *r)
{
	(*r)[0 * 4 + 0] = l->x;
	(*r)[0 * 4 + 1] = l->y;
	(*r)[0 * 4 + 2] = l->z;
	(*r)[0 * 4 + 3] = 0.0;
	(*r)[1 * 4 + 0] = t->x;
	(*r)[1 * 4 + 1] = t->y;
	(*r)[1 * 4 + 2] = t->z;
	(*r)[1 * 4 + 3] = 0.0;
	(*r)[2 * 4 + 0] = -f->x;
	(*r)[2 * 4 + 1] = -f->y;
	(*r)[2 * 4 + 2] = -f->z;
	(*r)[2 * 4 + 3] = 0.0;
	(*r)[3 * 4 + 0] = 0.0;
	(*r)[3 * 4 + 1] = 0.0;
	(*r)[3 * 4 + 2] = 0.0;
	(*r)[3 * 4 + 3] = 1.0;
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
