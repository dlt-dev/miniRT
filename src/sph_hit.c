/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:40:23 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 18:31:34 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// Adds the roots to the itxv, returns wether it added anything or not.
static bool	add_roots(t_pol2 *sph_eq, t_itx *itx, t_itxv *itxv)
{
	if (!itxv && sph_eq->delta >= 0.0)
		return (true);
	else if (!itxv)
		return (false);
	if (sph_eq->delta > 0)
	{
		itx->t = (-sph_eq->b - sqrt(sph_eq->delta)) / (2 * sph_eq->a);
		itxv_add(itxv, itx);
		itx->t = (-sph_eq->b + sqrt(sph_eq->delta)) / (2 * sph_eq->a);
		itxv_add(itxv, itx);
		return (true);
	}
	else if (deql(sph_eq->delta, 0.0))
	{
		itx->t = (-sph_eq->b / (2 * sph_eq->a));
		itxv_add(itxv, itx);
		return (true);
	}
	return (false);
}

bool	sph_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv)
{
	t_v4			sp_ray;
	t_pol2			sph_eq;
	t_itx			itx;
	t_ray			trf_ray;

	ray_trf(r, &(obj->itm), &trf_ray);
	sp_ray = v4_sub(trf_ray.o, obj->u_o.sp.c);
	sph_eq.a = v4_dot(trf_ray.dir, trf_ray.dir);
	sph_eq.b = 2 * v4_dot(trf_ray.dir, sp_ray);
	sph_eq.c = v4_dot(sp_ray, sp_ray) - 1;
	sph_eq.delta = sph_eq.b * sph_eq.b - 4 * sph_eq.a * sph_eq.c;
	itx.obj = obj;
	return (add_roots(&sph_eq, &itx, itxv));
}
