/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:19:20 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 10:19:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_clr	clr_sub(t_clr c1, t_clr c2)
{
	const t_itv	bounds = (t_itv){0.0, 1.0};

	return ((t_clr)
		{
			itv_clp(bounds, c1.r - c2.r),
			itv_clp(bounds, c1.g - c2.g),
			itv_clp(bounds, c1.b - c2.b),
			itv_clp(bounds, c1.t - c2.t),
		});
}
