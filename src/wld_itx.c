/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_itx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:47:26 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 18:36:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

int	wld_itx(const t_wld *world, const t_ray *ray, t_itxv *itxv)
{
	size_t	i;

	if (!world || !ray || !itxv)
		return (-1);
	i = 0;
	while (i < world->objs.len)
	{
		(world->objs.v[i].hit)(&(world->objs.v[i]), ray, itxv);
		i++;
	}
	itxv_sort(itxv);
	return (0);
}
