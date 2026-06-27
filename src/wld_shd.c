/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_shd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:31:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:54:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

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

static t_clr	refracted_clr(const t_wld *world, const t_itx *itx, int r)
{
	t_rfrd	data;
	t_itxv	rfr_itxv;

	data.nr = itx->n1 / itx->n2;
	data.cosi = v4_dot(itx->rd, itx->nrm);
	data.sin2t = data.nr * data.nr * (1 - data.cosi * data.cosi);
	if (deql(itx->obj->mtrl.tsp, 0.0) || r == 0 || data.sin2t > 1.0)
		return (clr_unpack(BLACK));
	data.cost = sqrt(1.0 - data.sin2t);
	data.rfr_ray.dir = v4_sub(v4_mul(itx->nrm, data.nr * data.cosi - data.cost),
			v4_mul(itx->rd, data.nr));
	data.rfr_ray.o = itx->uhp;
	rfr_itxv = itxv_crt(2);
	if (rfr_itxv.cap == 0)
		return (ft_err_prt("Refraction ERROR\n", 1), clr_unpack(BLACK));
	data.ref_clr = clr_mul(wld_clr_at(world, &data.rfr_ray, &rfr_itxv, r - 1),
			itx->obj->mtrl.tsp);
	itxv_dlt(&rfr_itxv);
	return (data.ref_clr);
}

static double	schlick(const t_itx *itx)
{
	double	cos;
	double	n;
	double	sin2_t;
	double	cos_t;
	double	r0;

	cos = v4_dot(itx->rd, itx->nrm);
	if (itx->n1 > itx->n2)
	{
		n = itx->n1 / itx->n2;
		sin2_t = n * n * (1.0 - cos * cos);
		if (sin2_t > 1.0)
			return (1.0);
		cos_t = sqrt(1.0 - sin2_t);
		cos = cos_t;
	}
	r0 = (itx->n1 - itx->n2) / ((itx->n1 + itx->n2));
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cos), 5));
}

// Color table is as follows [ambient, reflected, surface, refracted]
static t_clr	add_colours(t_clr clrs[4], const t_itx *itx)
{
	t_clr	clr1;
	double	rfl;

	if (itx->obj->mtrl.ref > 0.0 && itx->obj->mtrl.tsp > 0.0)
	{
		rfl = schlick(itx);
		clr1 = clr_add(clrs[2], clr_add(clr_mul(clrs[1], rfl),
					clr_mul(clrs[3], 1 - rfl)));
		return (clr_add(clr1, clr_mul(clrs[0], itx->obj->mtrl.amb)));
	}
	clr1 = clr_add(clrs[2], clr_add(clrs[1], clrs[3]));
	return (clr_add(clr1, clr_mul(clrs[0], itx->obj->mtrl.amb)));
}

// clrs : [ambient, reflected, surface, refracted]
t_clr	wld_shd(const t_wld *world, const t_itx *itx, t_itxv *itxv, int r)
{
	t_clr	clrs[4];
	size_t	i;
	bool	shade;

	i = 0;
	clrs[2] = clr_unpack(BLACK);
	while (i < world->lgts.len)
	{
		shade = is_shadowed(world, &(world->lgts.v[i]), itx, itxv);
		clrs[2] = clr_add(obj_lgt(itx->obj, &(world->lgts.v[i]), itx, shade),
				clrs[2]);
		i++;
	}
	clrs[1] = reflected_clr(world, itx, r);
	clrs[0] = clr_bld(obj_gclr(itx->obj, &itx->ohp), world->amb.clr);
	clrs[0] = clr_mul(clrs[0], world->amb.intensity);
	clrs[3] = refracted_clr(world, itx, r);
	return (add_colours(clrs, itx));
}
