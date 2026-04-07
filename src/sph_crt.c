/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 15:35:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_sph	sph_crt(void)
{
	t_sph	sphere;

	sphere.c = pt_crt(0, 0, 0);
	sphere.r = 1.0;
	sphere.clr = clr_unpack(0x002d46d2);
	m44_idm(&(sphere.tm));
	return (sphere);
}
