/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 09:05:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/08 11:42:52 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static int	obj_rot_axis(t_obj *obj, double ang, int (*rot_fn)(double, t_m44 *))
{
	t_m44	rot_mat;
	t_m44	irot_mat;
	t_m44	res_mat;

	if (rot_fn(ang, &rot_mat) == -1)
		return (-1);
	if (m44_inv_rot(&rot_mat, &irot_mat) == -1)
		return (-1);
	if (m44_prd(&rot_mat, &(obj->tm), &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(obj->tm)) == -1)
		return (-1);
	if (m44_prd(&(obj->itm), &irot_mat, &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(obj->itm)) == -1)
		return (-1);
	return (0);
}

// Angles are in radiant.
// Performs Rotation along X then Y then Z
int	obj_rot(t_obj *obj, double rx, double ry, double rz)
{
	int	err;

	err = 0;
	if (!deql(rx, 0.0))
		err = obj_rot_axis(obj, rx, m44_rotx);
	if (err == -1)
		return (-1);
	if (!deql(ry, 0.0))
		err = obj_rot_axis(obj, ry, m44_roty);
	if (err == -1)
		return (-1);
	if (!deql(rz, 0.0))
		err = obj_rot_axis(obj, rz, m44_rotz);
	if (err == -1)
		return (-1);
	return (0);
}
