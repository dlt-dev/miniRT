/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 13:04:27 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	sph_crt(void)
{
	t_obj	sphere;

	sphere.type = SPHERE;
	sphere.u_o.sp.c = pt_crt(0, 0, 0);
	sphere.u_o.sp.r = 1.0;
	m44_idm(&(sphere.tm));
	m44_idm(&(sphere.itm));
	m44_idm(&(sphere.itmt));
	mtl_ini(&(sphere.mtrl));
	sphere.hit = sph_hit;
	sphere.nrml = sph_nrml;
	sphere.gcord = sph_cord;
	return (sphere);
}
