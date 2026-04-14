/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/14 11:51:22 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	sph_crt(void)
{
	t_obj	sphere;

	sphere.type = SPHERE;
	sphere.u_o.sp.c = pt_crt(0, 0, 0);
	sphere.u_o.sp.r = 1.0;
	sphere.u_o.sp.clr = clr_unpack(0x002d46d2);
	m44_idm(&(sphere.tm));
	m44_idm(&(sphere.itm));
	m44_idm(&(sphere.trlm));
	m44_idm(&(sphere.itrlm));
	m44_idm(&(sphere.sclm));
	m44_idm(&(sphere.isclm));
	m44_idm(&(sphere.rotm));
	m44_idm(&(sphere.irotm));
	m44_idm(&(sphere.shem));
	m44_idm(&(sphere.ishem));
	return (sphere);
}
