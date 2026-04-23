/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 12:02:24 by cybourge         ###   ########.fr       */
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
	m44_idm(&(sphere.ittm));
	m44_idm(&(sphere.trlm));
	m44_idm(&(sphere.itrlm));
	m44_idm(&(sphere.sclm));
	m44_idm(&(sphere.isclm));
	m44_idm(&(sphere.rotm));
	m44_idm(&(sphere.irotm));
	m44_idm(&(sphere.shem));
	m44_idm(&(sphere.ishem));
	sphere.mtrl.clr = clr_unpack(WHITE);
	sphere.mtrl.amb = 0.1;
	sphere.mtrl.dif = 0.9;
	sphere.mtrl.spc = 0.9;
	sphere.mtrl.shi = 200.0;
	sphere.hit = sph_hit;
	sphere.nrml = sph_nrml;
	return (sphere);
}
