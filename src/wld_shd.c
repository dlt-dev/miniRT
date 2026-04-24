/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_shd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:31:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 09:48:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

// lthp : (Over Hit Point) to (Light) vector.
static bool	is_shadowed(const t_wld *world, const t_lgt *light, const t_itx *itx, t_itxv *itxv)
{
	t_v4	lthp;
	t_v4	dir;
	t_ray	shadow_ray;
	t_itx	hit;
	double	dist;
	
	itxv_clr(itxv);
	lthp = v4_sub(light->pos, itx->ohp);
	dist = v4_len(lthp);
	dir = v4_uni(lthp);
	shadow_ray = (t_ray) {.dir = dir, .o = itx->ohp};
	wld_itx(world, &shadow_ray, itxv);
	hit = itxv_hit(itxv);
	itxv_clr(itxv);
	if (hit.obj != NULL && hit.t < dist)
		return (true);
	return (false);
}

t_clr	wld_shd(const t_wld *world, const t_itx *itx, t_itxv *itxv)
{
	t_clr	fclr;
	size_t	i;
	bool	shadowed;

	i = 0;
	fclr = clr_unpack(BLACK);
	while (i < world->lgts.len)
	{
		shadowed = is_shadowed(world, &(world->lgts.v[i]), itx, itxv);
		fclr = clr_add(obj_lgt(itx->obj, &(world->lgts.v[i]), itx, shadowed), fclr);
		i++;
	}
	return (fclr);
}
