/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_lgts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:28:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:38:23 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scn_dflt_lgts(t_wld *world)
{
	t_clr	clr;

	world->lgts = lgtv_crt(2);
	if (world->lgts.cap == 0)
		return (-1);
	world->lgts.len = 1;
	clr = clr_mul(clr_unpack(WHITE), 0.60);
	lgt_set(&(world->lgts.v[0]), pt_crt(0, 10, -10), clr_pack(clr));
	clr = clr_mul(clr_unpack(WHITE), 0.5);
	lgt_set(&(world->lgts.v[1]), pt_crt(10, 10, -10), clr_pack(clr));
	world->amb.intensity = 0.5;
	world->amb.clr = clr_unpack(WHITE);
	return (0);
}
