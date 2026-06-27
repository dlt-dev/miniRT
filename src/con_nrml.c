/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_nrml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:58:40 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 16:16:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static t_v4	local_nrml(t_pt *opt, const t_obj *obj)
{
	double	yval;
	double	dist;
	t_v4	onrml;

	dist = opt->x * opt->x + opt->z * opt->z;
	if (dist < 1 && opt->y >= obj->u_o.co.max - EPS)
		onrml = v4_crt(0, 1, 0);
	else if (dist < 1 && opt->y <= obj->u_o.co.min + EPS)
		onrml = v4_crt(0, -1, 0);
	else
	{
		yval = sqrt(dist);
		if (opt->y > 0)
			yval = -yval;
		onrml = v4_crt(opt->x, yval, opt->z);
	}
	return (onrml);
}

int	con_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml)
{
	t_v4	onrml;
	t_pt	opt;

	if (!obj || !pt || !nrml)
		return (-1);
	if (m44_vprd(&(obj->itm), pt, &opt) == -1)
		return (-1);
	onrml = local_nrml(&opt, obj);
	if (m44_vprd(&(obj->itmt), &onrml, nrml) == -1)
		return (-1);
	nrml->w = 0;
	*nrml = v4_uni(*nrml);
	return (0);
}
