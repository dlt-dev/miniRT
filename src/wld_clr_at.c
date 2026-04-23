/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_clr_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:50:08 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 13:04:20 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

// If no objects are hit, Returns BLACK as default.
t_clr	wld_clr_at(const t_wld *world, const t_ray *ray, t_itxv *itxv)
{
	t_itx	hit;
	t_clr	clr;

	itxv_clr(itxv);
	wld_itx(world, ray, itxv);
	hit = itxv_hit(itxv);
	if (hit.obj == NULL)
		return (clr_unpack(BLACK));
	itx_cal(&hit, ray);
	clr = wld_shd(world, &hit);
	itxv_clr(itxv);
	return (clr);
}
