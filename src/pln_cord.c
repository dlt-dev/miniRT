/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:03:40 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 14:20:25 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// P : point in 3D Object space
// returns (u,v) coordinates of P on a xz plane
// where u,v are in [0,1].
t_pt	pln_cord(const t_pt *point)
{
	return(pt_crt(fabs(floor(point->x) - point->x), fabs(floor(point->z) - point->z), 0));
}