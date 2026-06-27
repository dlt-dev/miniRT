/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:36:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 16:10:34 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

// Function that checks if any non transparent objects have been hit by the 
// shadow ray
// returns true if there is shadow, false otherwise.
static bool	check_obj(const t_itxv *itxv, double dist)
{
	size_t	i;

	i = 0;
	while (i < itxv->len)
	{
		if (itxv->v[i].t <= 0 || itxv->v[i].t > dist)
			i++;
		else
		{
			if (itxv->v[i].obj->mtrl.tsp < 1.0)
				return (true);
		}
		i++;
	}
	return (false);
}

// lthp : (Over Hit Point) to (Light) vector.
bool	is_shadowed(
	const t_wld *world,
	const t_lgt *light,
	const t_itx *itx,
	t_itxv *itxv)
{
	t_v4	lthp;
	t_v4	dir;
	t_ray	shadow_ray;
	double	dist;
	bool	test;

	itxv_clr(itxv);
	lthp = v4_sub(light->pos, itx->ohp);
	dist = v4_len(lthp);
	dir = v4_uni(lthp);
	shadow_ray = (t_ray){.dir = dir, .o = itx->ohp};
	wld_itx(world, &shadow_ray, itxv);
	test = check_obj(itxv, dist);
	itxv_clr(itxv);
	return (test);
}
