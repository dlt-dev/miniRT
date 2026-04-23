/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_shd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:31:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 13:51:41 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_clr	wld_shd(const t_wld *world, const t_itx *itx)
{
	t_clr	fclr;
	size_t	i;

	i = 0;
	fclr = clr_unpack(BLACK);
	while (i < world->lgts.len)
	{
		fclr = clr_add(obj_lgt(itx->obj, &(world->lgts.v[i]), itx), fclr);
		i++;
	}
	return (fclr);
}
