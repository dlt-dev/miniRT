/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trf_scl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:58:02 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 10:50:07 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

// m1 and m2 are assumed to be pure scaling matrixes.
int	add_sclm(t_m44 const *m1, t_m44 const *m2, t_m44 *res)
{
	if (!m1 || !m2 || !res)
		return (-1);
	(*res)[0] = (*m1)[0] * (*m2)[0];
	(*res)[5] = (*m1)[5] * (*m2)[5];
	(*res)[10] = (*m1)[10] * (*m2)[10];
	return (0);
}

int	trf_scl(t_trf *trf, double sx, double sy, double sz)
{
	t_m44	scl_mat;
	t_m44	iscl_mat;

	if (m44_scl(sx, sy, sz, &scl_mat) == -1)
		return (-1);
	if (m44_inv_scl(&scl_mat, &iscl_mat) == -1)
		return (-1);
	if (add_sclm(&scl_mat, &(trf->sclm), &(trf->sclm)) == -1)
		return (-1);
	if (add_sclm(&iscl_mat, &(trf->isclm), &(trf->isclm)) == -1)
		return (-1);
	return (0);
}
