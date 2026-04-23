/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgt_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:40:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 10:42:00 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void	lgt_set(t_lgt *light, t_pt pos, uint32_t clr)
{
	if (!light)
		return ;
	light->pos = pos;
	light->clr = clr_unpack(clr);
}
