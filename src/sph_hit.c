/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:40:23 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 15:34:41 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// Used to store the data relating to a second degree polynomial.
typedef struct s_polynome_2
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	r1;
	double	r2;
}	t_pol2;

bool	sph_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv)
{
	const t_sph		*sp = &(obj->u_o.sp);
	t_v4			sp_ray;
	t_pol2			sph_eq;
	t_itx			itx;
	t_ray			trf_ray;
	t_m44			trf_inv;

	m44_inv(&(sp->tm), &trf_inv);
	ray_trf(r, &trf_inv, &trf_ray);
	sp_ray = v4_sub(trf_ray.o, sp->c);
	sph_eq.a = v4_dot(trf_ray.dir, trf_ray.dir);
	sph_eq.b = 2 * v4_dot(trf_ray.dir, sp_ray);
	sph_eq.c = v4_dot(sp_ray, sp_ray) - 1;
	sph_eq.delta = sph_eq.b * sph_eq.b - 4 * sph_eq.a * sph_eq.c;
	itx.obj = obj;
	if (sph_eq.delta > 0)
	{
		itx.t = (-sph_eq.b - sqrt(sph_eq.delta)) / (2 * sph_eq.a);
		itxv_add(itxv, &itx);
		itx.t = (-sph_eq.b + sqrt(sph_eq.delta)) / (2 * sph_eq.a);
		itxv_add(itxv, &itx);
		return (true);
	}
	else if (sph_eq.delta == 0)
	{
		itx.t = (-sph_eq.b / (2 * sph_eq.a));
		itxv_add(itxv, &itx);
		return (true);
	}
	return (false);
}
