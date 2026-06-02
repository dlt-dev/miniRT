/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_nrml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:38:01 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 11:19:04 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// obj	 : Sphere, wpt : Point in World Space, 
// wnrml : Set by the function : Normal to the surface in World Space
int	sph_nrml(const t_obj *obj, const t_pt *wpt, t_v4 *wnrml)
{
	t_v4	onrml;
	t_pt	opt;

	if (!obj || !wpt || !wnrml)
		return (-1);
	if (m44_vprd(&(obj->itm), wpt, &opt) == -1)
		return (-1);
	onrml = v4_sub(opt, pt_crt(0.0, 0.0, 0.0));
	if (m44_vprd(&(obj->itmt), &onrml, wnrml) == -1)
		return (-1);
	wnrml->w = 0;
	*wnrml = v4_uni(*wnrml);
	return (0);
}
