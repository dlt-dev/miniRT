/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_shd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:31:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/03 10:34:13 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

// lthp : (Over Hit Point) to (Light) vector.
static bool	is_shadowed(
	const t_wld *world,
	const t_lgt *light,
	const t_itx *itx,
	t_itxv *itxv)
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
	shadow_ray = (t_ray){.dir = dir, .o = itx->ohp};
	wld_itx(world, &shadow_ray, itxv);
	hit = itxv_hit(itxv);
	itxv_clr(itxv);
	if (hit.obj != NULL && hit.t < dist)
		return (true);
	return (false);
}

// TBD : Better Error Handling
static t_clr	reflected_clr(const t_wld *world, const t_itx *itx, int r)
{
	t_ray	rfl_ray;
	t_itxv	rfl_itxv;
	t_clr	rfl_clr;

	if (deql(itx->obj->mtrl.rfl, 0.0) || r <= 0)
		return (clr_unpack(BLACK));
	rfl_itxv = itxv_crt(2);
	if (rfl_itxv.cap == 0)
		return (ft_err_prt("Reflection ERROR\n", 1), clr_unpack(BLACK));
	rfl_ray.dir = itx->rflv;
	rfl_ray.o = itx->ohp;
	rfl_clr = wld_clr_at(world, &rfl_ray, &rfl_itxv, r - 1);
	itxv_dlt(&rfl_itxv);
	return (clr_mul(rfl_clr, itx->obj->mtrl.rfl));
}

t_clr	wld_shd(const t_wld *world, const t_itx *itx, t_itxv *itxv, int r)
{
	t_clr	fclr;
	t_clr	aclr;
	t_clr	rclr;
	size_t	i;
	bool	shadowed;

	i = 0;
	fclr = clr_unpack(BLACK);
	while (i < world->lgts.len)
	{
		shadowed = is_shadowed(world, &(world->lgts.v[i]), itx, itxv);
		fclr = clr_add(obj_lgt(itx->obj, &(world->lgts.v[i]), itx, shadowed),
				fclr);
		i++;
	}
	rclr = reflected_clr(world, itx, r);
	aclr = clr_bld(world->amb.clr,
			clr_mul(obj_gclr(itx->obj, &(itx->ohp)), itx->obj->mtrl.amb));
	fclr = clr_add(fclr, aclr);
	fclr = clr_add(fclr, rclr);
	return (fclr);
}
