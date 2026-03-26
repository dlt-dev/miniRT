/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:19:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 10:34:52 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_clr	clr_mul(t_clr c1, double i)
{
	const t_itv	bounds = (t_itv){0.0, 1.0};

	return ((t_clr)
		{
			itv_clp(bounds, c1.r * i),
			itv_clp(bounds, c1.g * i),
			itv_clp(bounds, c1.b * i),
			itv_clp(bounds, c1.t * i),
		});
}
