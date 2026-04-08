/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_scl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:58:02 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/08 10:57:46 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	obj_scl(t_obj *obj, double sx, double sy, double sz)
{
	t_m44	scl_mat;
	t_m44	iscl_mat;
	t_m44	res_mat;

	if (m44_scl(sx, sy, sz, &scl_mat) == -1)
		return (-1);
	if (m44_inv_scl(&scl_mat, &iscl_mat) == -1)
		return (-1);
	if (m44_prd(&scl_mat, &(obj->tm), &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(obj->tm)) == -1)
		return (-1);
	if (m44_prd(&(obj->itm), &iscl_mat, &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(obj->itm)) == -1)
		return (-1);
	return (0);
}
