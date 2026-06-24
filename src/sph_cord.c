/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:33:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 14:06:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// P : point in 3D Object space
// returns (u,v) coordinates of P on a unit sphere
// where u,v are in [0,1].
t_pt	sph_cord(const t_pt *point)
{
	const double	theta = atan2(point->x, point->z);
	const t_v4		vec = v4_crt(point->x, point->y, point->z);
	const double	rad = v4_len(vec);
	const double	phi = acos(point->y / rad);
	const double	raw_u = theta / (PI);
	const double	u = 1 - (raw_u + 0.5);
	const double	v = 1 - phi / PI; 
	return (pt_crt(u,v,0));
}