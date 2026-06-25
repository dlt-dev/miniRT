/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_nrml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:38:01 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 16:52:35 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void	perturb_nrm(const t_obj *obj, t_v4 *onrml, t_pt *opt)
{
	t_pt	pat_pt;
	t_pt	fin_pt;
	t_clr	bumpc;
	t_v4	bumpv;
	double	bumpl;

	if (obj->gcord == NULL || obj->mtrl.hmap == NULL )
		return ;
	m44_vprd(&(obj->mtrl.itm), opt, &pat_pt);
	fin_pt = obj->gcord(&pat_pt);
	bumpc = ftex_clr(&(obj->mtrl.hmap->u_tex.ftex), &fin_pt);
	bumpv = v4_crt(bumpc.r, bumpc.g, bumpc.b);
	bumpl = v4_len(bumpv);
	onrml->y = onrml->y + bumpl * 5;
}

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
	perturb_nrm(obj, &onrml, &opt);
	if (m44_vprd(&(obj->itmt), &onrml, wnrml) == -1)
		return (-1);
	wnrml->w = 0;
	*wnrml = v4_uni(*wnrml);
	return (0);
}
