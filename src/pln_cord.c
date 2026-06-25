/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:03:40 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:19:31 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// P : point in 3D Object space
// returns (u,v) coordinates of P on a xz plane
// where u,v are in [0,1].
t_pt	pln_cord(const t_pt *point)
{
	t_pt	uv;

	uv.x = fmod(point->x, 1);
	uv.y = fmod(point->z, 1);
	uv.z = 0.0;
	uv.w = 1.0;
	return (uv);
}
