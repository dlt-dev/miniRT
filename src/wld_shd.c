/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_shd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:31:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 12:58:41 by cybourge         ###   ########.fr       */
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
static double	is_shadowed(
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
	const double	n_ratio = itx->n1 / itx->n2;
	const double	cos_i = v4_dot(itx->rd, itx->nrm);
	const double	sin2_t = n_ratio * n_ratio * (1 - cos_i * cos_i);
	double			cos_t;
	t_ray			rfr_ray;
	t_clr			clrs[3];
	t_itxv			rfr_itxv;

	if (deql(itx->obj->mtrl.tsp, 0.0) || r == 0 || sin2_t > 1.0)
		return (clr_unpack(BLACK));
	cos_t = sqrt(1.0 - sin2_t);
	rfr_ray.dir = v4_sub(v4_mul(itx->nrm, n_ratio * cos_i - cos_t),
			v4_mul(itx->rd, n_ratio));
	rfr_ray.o = itx->uhp;
	rfr_itxv = itxv_crt(2);
	if (rfr_itxv.cap == 0)
		return (ft_err_prt("Refraction ERROR\n", 1), clr_unpack(BLACK));
	clrs[3] = clr_mul(wld_clr_at(world, &rfr_ray, &rfr_itxv, r - 1),
			itx->obj->mtrl.tsp);
	itxv_dlt(&rfr_itxv);
	return (clrs[3]);
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
	r0 = (itx->n1 - itx->n2) / ((itx->n1 + itx->n2) * (itx->n1 + itx->n2));
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
		return (clr_add(clr1, clrs[0]));
	}
	clr1 = clr_add(clrs[2], clr_add(clrs[1], clrs[3]));
	return (clr_add(clr1, clrs[0]));
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
// ambclr = clr_add(obj_gclr(itx->obj, &(itx->ohp)),
// 		clr_mul(world->amb.clr, itx->obj->mtrl.amb));

// clrs[0] = clr_mul(world->amb.clr,
// 			world->amb.intensity * itx->obj->mtrl.amb);