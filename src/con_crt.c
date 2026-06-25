/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:13:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:00:02 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	con_crt(void)
{
	t_obj	cone;
	
	cone.type = CONE;
	cone.u_o.co.closed = true;
	cone.u_o.co.min = -1;
	cone.u_o.co.max = 0;
	m44_idm(&(cone.tm));
	m44_idm(&(cone.itm));
	m44_idm(&(cone.itmt));
	mtl_ini(&(cone.mtrl));
	cone.hit = con_hit;
	cone.nrml = con_nrml;
	cone.gcord = con_cord;
	return (cone);
}
