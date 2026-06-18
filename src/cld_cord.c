/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cld_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:44:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/18 12:20:20 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// P : Point in 3D Space
// Returns the coordinates of P in cylindrical form.
t_pt	cld_cord(const t_pt *point)
{
	const double theta = atan2(point->x, point->z) + PI;
	const double u = theta / PI;
	//const double u = 1 - raw_u + 0.5;
	//const double v = (int) floor(point->y) % 1;
	
	return (pt_crt(u, point->y * (PI), 0.0));
}