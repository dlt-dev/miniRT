/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_trl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:39:04 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/15 11:15:11 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// m1 and m2 are assumed to be pure translation matrices only.
int	add_trlm(t_m44 const *m1, t_m44 const *m2, t_m44 *res)
{
	if (!m1 || !m2 || !res)
		return (-1);
	if (m44_idm(res) == -1)
		return (-1);
	(*res)[3] = (*m1)[3] + (*m2)[3];
	(*res)[7] = (*m1)[7] + (*m2)[7];
	(*res)[11] = (*m1)[11] + (*m2)[11];
	return (0);
}

int	obj_trl(t_obj *obj, double tx, double ty, double tz)
{
	t_m44	trl_mat;
	t_m44	itrl_mat;

	if (m44_trl(tx, ty, tz, &trl_mat) == -1)
		return (-1);
	if (m44_inv_trl(&trl_mat, &itrl_mat) == -1)
		return (-1);
	if (add_trlm(&trl_mat, &(obj->trlm), &(obj->trlm)) == -1)
		return (-1);
	if (add_trlm(&itrl_mat, &(obj->itrlm), &(obj->itrlm)) == -1)
		return (-1);
	return (0);
}
