/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cld_nrml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:21:36 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:27:33 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	cld_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml)
{
	t_v4	onrml;
	t_pt	opt;
	double	dist;

	if (!obj || !pt || !nrml)
		return (-1);
	if (m44_vprd(&(obj->itm), pt, &opt) == -1)
		return (-1);
	dist = opt.x * opt.x + opt.z * opt.z;
	if (dist < 1 && opt.y >= obj->u_o.cy.max - EPS)
		onrml = v4_crt(0, 1, 0);
	else if (dist < 1 && opt.y <= obj->u_o.cy.min + EPS)
		onrml = v4_crt(0, -1, 0);
	else
		onrml = v4_crt(opt.x, 0, opt.z);
	if (m44_vprd(&(obj->itmt), &onrml, nrml) == -1)
		return (-1);
	nrml->w = 0;
	*nrml = v4_uni(*nrml);
	return (0);
}
