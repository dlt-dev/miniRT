/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_lgts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:28:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/03 09:47:35 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scn_dflt_lgts(t_wld *world)
{
	t_clr	clr;

	world->lgts = lgtv_crt(2);
	if (world->lgts.cap == 0)
		return (-1);
	world->lgts.len = 2;
	clr = clr_mul(clr_unpack(WHITE), 0.60);
	lgt_set(&(world->lgts.v[0]), pt_crt(-10, 10, -10), clr_pack(clr));
	clr = clr_mul(clr_unpack(WHITE), 0.5);
	lgt_set(&(world->lgts.v[1]), pt_crt(10, 10, -10), clr_pack(clr));
	// world->amb.intensity = 0.01;
	// world->amb.clr = clr_unpack(WHITE);
	memset(&(world->amb), 0, sizeof(t_ambl));
	return (0);
}
