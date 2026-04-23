/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:09:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:45:59 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// The fields of the color are clamped to the [0, 1.0] interval.
t_clr	clr_add(t_clr c1, t_clr c2)
{
	const t_itv	bounds = (t_itv){0.0, 1.0};
	t_clr		sum_clr;

	sum_clr.t = itv_clp(bounds, c1.t + c2.t);
	sum_clr.r = itv_clp(bounds, c1.r + c2.r);
	sum_clr.g = itv_clp(bounds, c1.g + c2.g);
	sum_clr.b = itv_clp(bounds, c1.b + c2.b);
	return (sum_clr);
}
