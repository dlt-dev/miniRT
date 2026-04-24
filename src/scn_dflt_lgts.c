/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_lgts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:28:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 10:30:41 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scn_dflt_lgts(t_wld *world)
{
	world->lgts = lgtv_crt(2);
	if (world->lgts.cap == 0)
		return (-1);
	world->lgts.len = 2;
	lgt_set(&(world->lgts.v[0]), pt_crt(-10, 10, -10), WHITE);
	lgt_set(&(world->lgts.v[1]), pt_crt(10, 10, 10), WHITE);
	return (0);
}
