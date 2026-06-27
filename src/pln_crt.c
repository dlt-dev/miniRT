/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:58:03 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:55:56 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	pln_crt(void)
{
	t_obj	plane;

	plane.type = PLANE;
	plane.u_o.pl.nrml = v4_crt(0, 1, 0);
	m44_idm(&(plane.tm));
	m44_idm(&(plane.itm));
	m44_idm(&(plane.itmt));
	mtl_ini(&(plane.mtrl));
	plane.mtrl.clr = clr_unpack(WHITE);
	plane.hit = pln_hit;
	plane.nrml = pln_nrml;
	plane.gcord = pln_cord;
	return (plane);
}
