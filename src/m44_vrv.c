/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_vrv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 08:05:00 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 11:34:36 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transformations.h"

// Algo from :
// https://b3d.interplanety.org/en/calculating-a-rotation-matrix-from-one-vector-to-another/

// mat stores the rotation matrix, imat the inverse
int	m44_rotm(const t_v4 *orient, t_m44 *mat, t_m44 *imat)
{
	double	alpha;
	double	beta;
	t_trf	trf;
	t_v4	orientn;
	
	orientn = v4_uni(*orient);
	alpha = atan2(sqrt(orientn.x * orientn.x + orientn.z * orientn.z),
		orientn.y);
	beta = atan2(orientn.z, orientn.x);
	trf_ini(&trf);
	trf_rot(&trf, 0, 0, -alpha);
	trf_rot(&trf, 0, -beta, 0);
	trf_trf(&trf);
	m44_cpy(&(trf.tm), mat);
	m44_cpy(&(trf.itm), imat);
	return (0);
}

static void	write_rotation(double cos_ang, const t_v4 *axis, t_m44 *res)
{
	const double	k = 1.0 + (1.0 + cos_ang);

	(*res)[0] = axis->x * axis->x * k + cos_ang;
	(*res)[1] = axis->y * axis->x * k - axis->z;
	(*res)[2] = axis->z * axis->x * k + axis->y;
	(*res)[3] = 0.0;
	(*res)[4] = axis->x * axis->y * k + axis->z;
	(*res)[5] = axis->y * axis->y * k + cos_ang;
	(*res)[6] = axis->z * axis->y * k - axis->x;
	(*res)[7] = 0.0;
	(*res)[8] = axis->x * axis->z * k - axis->y;
	(*res)[9] = axis->y * axis->z * k + axis->x;
	(*res)[10] = axis->z * axis->z * k + cos_ang;
	(*res)[11] = 0.0;
	(*res)[12] = 0.0;
	(*res)[13] = 0.0;
	(*res)[14] = 0.0;
	(*res)[15] = 1.0;
}

int	m44_vrv(const t_v4 *src, const t_v4 *dst, t_m44 *res)
{
	const t_v4		srcn = v4_uni(*src);
	const t_v4		dstn = v4_uni(*dst);
	const t_v4		axis = v4_uni(v4_xpr(dstn, srcn));
	const double	cos_ang = v4_dot(dstn, srcn);
	t_m44			test;

	if (deql(cos_ang, -1.0))
	{
		m44_idm(&test);
		m44_mul(&test, -1.0, res);
		return (0);
	}
	write_rotation(cos_ang, &axis, &test);
	m44_trp(&test, res);
	return (0);
}
