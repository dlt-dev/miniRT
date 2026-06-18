/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:33:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/18 11:35:54 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// P : point in 3D space
// returns spherical coordinates of P on a unit sphere
t_pt	sph_cord(const t_pt *point)
{
	const double theta = atan2(-(point->z), point->x) + PI;
	const double phi = acos(-(point->y));
	const double u = phi / PI;
	const double v = theta / PI;

	return (pt_crt(u,v,0));
}