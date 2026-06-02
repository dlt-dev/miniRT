/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trf_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 09:05:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 10:50:02 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

static int	trf_rot_axis(t_trf *trf, double ang, int (*rot_fn)(double, t_m44 *))
{
	t_m44	rot_mat;
	t_m44	irot_mat;
	t_m44	res_mat;

	if (rot_fn(ang, &rot_mat) == -1)
		return (-1);
	if (m44_inv_rot(&rot_mat, &irot_mat) == -1)
		return (-1);
	if (m44_prd(&rot_mat, &(trf->rotm), &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(trf->rotm)) == -1)
		return (-1);
	if (m44_prd(&(trf->irotm), &irot_mat, &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(trf->irotm)) == -1)
		return (-1);
	return (0);
}

// Angles are in radiant.
// Performs Rotation along X then Y then Z
int	trf_rot(t_trf *trf, double rx, double ry, double rz)
{
	int	err;

	err = 0;
	if (!deql(rx, 0.0))
		err = trf_rot_axis(trf, rx, m44_rotx);
	if (err == -1)
		return (-1);
	if (!deql(ry, 0.0))
		err = trf_rot_axis(trf, ry, m44_roty);
	if (err == -1)
		return (-1);
	if (!deql(rz, 0.0))
		err = trf_rot_axis(trf, rz, m44_rotz);
	if (err == -1)
		return (-1);
	return (0);
}
