/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cld_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:44:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:23:23 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// const double	theta = atan2(point->x, point->z);
// const double	raw_u = theta / (2 * PI);
// const double	u = 1.0 - (raw_u + 0.5);
// const double	v = fabs(floor(point->y) - point->y);
// return (pt_crt(u,v,0));

// P : point in 3D Object space
// returns (u,v) coordinates of P on a Y axis cylinder
// where u,v are in [0,1].
t_pt	cld_cord(const t_pt *point)
{
	t_pt	uv;
	double	theta;

	theta = atan2(point->x, point->z);
	uv.x = 1 - ((theta / (2 * PI)) + 0.5);
	uv.y = fmod(point->y, 1);
	uv.z = 0.0;
	uv.w = 1.0;
	return (uv);
}
