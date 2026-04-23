/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:19:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:48:31 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// The fields of the color are clamped to the [0, 1.0] interval.
t_clr	clr_mul(t_clr c1, double i)
{
	const t_itv	bounds = (t_itv){0.0, 1.0};
	t_clr		mul_clr;

	mul_clr.t = itv_clp(bounds, c1.t * i);
	mul_clr.r = itv_clp(bounds, c1.r * i);
	mul_clr.g = itv_clp(bounds, c1.g * i);
	mul_clr.b = itv_clp(bounds, c1.b * i);
	return (mul_clr);
}
