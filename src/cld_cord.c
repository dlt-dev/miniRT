/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cld_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:44:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 15:19:52 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// P : Point in 3D Space
// Returns the coordinates of P in cylindrical form.
// t_pt	cld_cord(const t_pt *point)
// {
// 	const double theta = atan2(point->x, point->z) + PI;
// 	const double u = theta / PI;
// 	//const double u = 1 - raw_u + 0.5;
// 	//const double v = (int) floor(point->y) % 1;
	
// 	return (pt_crt(u, point->y * (PI), 0.0));
// }

// P : point in 3D Object space
// returns (u,v) coordinates of P on a Y axis cylinder
// where u,v are in [0,1].
t_pt	cld_cord(const t_pt *point)
{
	const double	theta = atan2(point->x, point->z);
	const double	raw_u = theta / (2 * PI);
	const double	u = 1.0 - (raw_u + 0.5);
	const double	v = fabs(floor(point->y) - point->y);
	
	return (pt_crt(u,v,0));
}