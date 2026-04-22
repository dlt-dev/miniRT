/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_crt_dflt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:17:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:08:51 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

// Inits to a default world with:
//  - WHITE light source at (-10,10,-10).
//  - Unit sphere at the Origin.
//  - 0.5 radius sphere at the Origin.
int	wld_ini_dflt(t_wld *wld)
{
	wld->objs = objv_crt(2);
	if (wld->objs.cap == 0)
		return (-1);
	wld->lgts = lgtv_crt(1);
	if (wld->lgts.cap == 0)
		return (objv_dlt(&(wld->objs)), -1);
	wld->objs.v[0] = sph_crt();
	wld->objs.v[0].mtrl.clr = (t_clr){0, 0.8, 1.0, 0.6};
	wld->objs.v[0].mtrl.dif = 0.7;
	wld->objs.v[0].mtrl.spc = 0.2;
	wld->objs.v[1] = sph_crt();
	obj_scl(&(wld->objs.v[1]), 0.5, 0.5, 0.5);
	obj_trf(&(wld->objs.v[0]));
	obj_trf(&(wld->objs.v[1]));
	lgt_set(&(wld->lgts.v[0]), pt_crt(-10, 10, -10), WHITE);
	wld->objs.len = 2;
	wld->lgts.len = 1;
	return (0);
}
