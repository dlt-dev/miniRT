/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:33:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:57 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// P : point in 3D Object space
// returns (u,v) coordinates of P on a unit sphere
// where u,v are in [0,1].
// Rectangular projection
t_pt	sph_cord(const t_pt *point)
{
	t_pt	uv;
	double	theta;
	double	phi;

	theta = atan2(point->x, point->z);
	phi = acos(point->y);
	uv.x = 1 - ((theta / (2 * PI)) + 0.5);
	uv.y = 1 - (phi / PI);
	uv.z = 0.0;
	uv.w = 1.0;
	return (uv);
}

// Square projection
t_pt	sph_cord2(const t_pt *point)
{
	const double	theta = atan2(point->x, point->z);
	const t_v4		vec = v4_crt(point->x, point->y, point->z);
	const double	phi = acos(point->y / v4_len(vec));
	const double	u = 1 - (theta / PI + 0.5);
	const double	v = 1 - phi / PI;

	return (pt_crt(u, v, 0));
}
