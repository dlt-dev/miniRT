/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_scl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:58:02 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 10:19:48 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

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

int	obj_scl(t_obj *obj, double sx, double sy, double sz)
{
	t_m44	scl_mat;
	t_m44	iscl_mat;

	if (m44_scl(sx, sy, sz, &scl_mat) == -1)
		return (-1);
	if (m44_inv_scl(&scl_mat, &iscl_mat) == -1)
		return (-1);
	if (add_sclm(&scl_mat, &(obj->sclm), &(obj->sclm)) == -1)
		return (-1);
	if (add_sclm(&iscl_mat, &(obj->isclm), &(obj->isclm)) == -1)
		return (-1);
	return (0);
}
