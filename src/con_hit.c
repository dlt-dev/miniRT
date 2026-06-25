/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:16:35 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:25:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static bool	check_caps(const t_ray *ray, double t, double radius)
{
	const double	x = ray->o.x + t * ray->dir.x;
	const double	z = ray->o.z + t * ray->dir.z;

	if ((x * x + z * z) <= radius * radius)
		return (true);
	return (false);
}

static bool	intersect_caps(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_itx	itx;
	bool	has_hit;

	has_hit = false;
	if (!(obj->u_o.co.closed) || deql(ray->dir.y, 0.0))
		return (has_hit);
	itx.obj = obj;
	itx.t = (obj->u_o.co.min - ray->o.y) / ray->dir.y;
	if (check_caps(ray, itx.t, obj->u_o.co.min))
	{
		itxv_add(itxv, &itx);
		has_hit = true;
	}
	itx.t = (obj->u_o.co.max - ray->o.y) / ray->dir.y;
	if (check_caps(ray, itx.t, obj->u_o.co.max))
	{
		itxv_add(itxv, &itx);
		has_hit = true;
	}
	return (has_hit);
}

static bool	intersect_walls(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_pol2	con_eq;
	t_itx	itx;
	double	height;
	bool	hit;

	hit = false;
	itx.obj = obj;
	con_eq.a = ray->dir.x * ray->dir.x - ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z;
	con_eq.b = 2 * ray->o.x * ray->dir.x - 2 * ray->o.y * ray->dir.y + 2 * ray->o.z * ray->dir.z;
	con_eq.c = ray->o.x * ray->o.x - ray->o.y * ray->o.y + ray->o.z * ray->o.z;
	con_eq.delta = con_eq.b * con_eq.b - (4 * con_eq.a * con_eq.c);
	if (deql(con_eq.a, 0.0))
	{
		if (!deql(con_eq.b, 0.0))
		{
			itx.t = -con_eq.c / (2 * con_eq.b);
			itxv_add(itxv, &itx);
			hit = true;
		}
	}
	if (con_eq.delta < 0.0)
		return (false);
	itx.t = (-con_eq.b - sqrt(con_eq.delta)) / (2.0 * con_eq.a);
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.co.min && height < obj->u_o.co.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}
	itx.t = (-con_eq.b + sqrt(con_eq.delta)) / (2.0 * con_eq.a);
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.co.min && height < obj->u_o.co.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}
	return (hit);
}

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
	if (intersect_caps(obj, &trf_ray, itxv))
		hit = true;
	return (hit);
}
