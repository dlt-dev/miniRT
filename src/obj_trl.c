/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_trl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:39:04 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/08 09:01:21 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// Left multiply the transformation matrix.
// Right multiply the inverse.
int	obj_trl(t_obj *obj, double tx, double ty, double tz)
{
	t_m44	trl_mat;
	t_m44	itrl_mat;
	t_m44	res_mat;

	if (m44_trl(tx, ty, tz, &trl_mat) == -1)
		return (-1);
	if (m44_inv_trl(&trl_mat, &itrl_mat) == -1)
		return (-1);
	if (m44_prd(&trl_mat, &(obj->tm), &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(obj->tm)) == -1)
		return (-1);
	if (m44_prd(&(obj->itm), &itrl_mat, &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(obj->itm)) == -1)
		return (-1);
	return (0);
}
