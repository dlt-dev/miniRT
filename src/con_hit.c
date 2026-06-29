/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:16:35 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/29 07:57:46 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void	solve_eq(t_pol2 *con_eq, const t_ray *ray)
{
	con_eq->a = ray->dir.x * ray->dir.x - ray->dir.y * ray->dir.y
		+ ray->dir.z * ray->dir.z;
	con_eq->b = 2 * ray->o.x * ray->dir.x - 2 * ray->o.y * ray->dir.y
		+ 2 * ray->o.z * ray->dir.z;
	con_eq->c = ray->o.x * ray->o.x - ray->o.y * ray->o.y
		+ ray->o.z * ray->o.z;
	con_eq->delta = con_eq->b * con_eq->b - (4 * con_eq->a * con_eq->c);
	if (con_eq->delta >= 0 && !deql(con_eq->a, 0.0))
	{
		con_eq->r1 = (-con_eq->b - sqrt(con_eq->delta)) / (2.0 * con_eq->a);
		con_eq->r2 = (-con_eq->b + sqrt(con_eq->delta)) / (2.0 * con_eq->a);
	}
	else
	{
		con_eq->r1 = NAN;
		con_eq->r2 = NAN;
	}
}

static bool	solve_root(t_pol2 *con_eq, const t_ray *ray,
	const t_obj *obj, t_itxv *itxv)
{
	t_itx	itx;
	bool	hit;
	double	height;

	hit = false;
	itx.obj = obj;
	itx.t = con_eq->r1;
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.co.min && height < obj->u_o.co.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}
	itx.t = con_eq->r2;
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.co.min && height < obj->u_o.co.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}
	return (hit);
}

static bool	intersect_walls(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_pol2	con_eq;
	t_itx	itx;
	bool	hit;

	hit = false;
	itx.obj = obj;
	solve_eq(&con_eq, ray);
	if (deql(con_eq.a, 0.0) && !deql(con_eq.b, 0.0))
	{
		itx.t = -con_eq.c / (2 * con_eq.b);
		itxv_add(itxv, &itx);
		hit = true;
	}
	if (con_eq.delta < 0.0)
		return (false);
	hit = solve_root(&con_eq, ray, obj, itxv);
	return (hit);
}

// In con_hit2.c
bool	con_intersect_caps(const t_obj *obj, const t_ray *ray, t_itxv *itxv);

// The cone is implemented as a doubled-napped cone, that is then truncated
// into a regular cone.
bool	con_hit(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_ray	trf_ray;
	bool	hit;

	ray_trf(ray, &(obj->itm), &trf_ray);
	hit = false;
	if (intersect_walls(obj, &trf_ray, itxv))
		hit = true;
	if (con_intersect_caps(obj, &trf_ray, itxv))
		hit = true;
	return (hit);
}
