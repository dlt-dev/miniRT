/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_bld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:23:47 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:57:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// The fields of the color are clamped to the [0, 1.0] interval.
t_clr	clr_bld(t_clr c1, t_clr c2)
{
	const t_itv	bounds = itv_crt(0.0, 1.0);
	t_clr		bld_clr;

	bld_clr.t = itv_clp(bounds, c1.t * c2.t);
	bld_clr.r = itv_clp(bounds, c1.r * c2.r);
	bld_clr.g = itv_clp(bounds, c1.g * c2.g);
	bld_clr.b = itv_clp(bounds, c1.b * c2.b);
	return (bld_clr);
}
