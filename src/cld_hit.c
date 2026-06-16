/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cld_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:03:27 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/16 16:36:58 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static bool	check_caps(const t_ray *ray, double t)
{
	const double x = ray->o.x + t * ray->dir.x;
	const double z = ray->o.z + t * ray->dir.z;
	if ((x * x + z * z) <= 1.0)
		return (true);
	return (false);
}

static bool	intersect_caps(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_itx	itx;
	bool	has_hit;

	has_hit = false;
	if (!(obj->u_o.cy.closed) || deql(ray->dir.y, 0.0))
		return (has_hit);
	itx.obj = obj;
	itx.t = (obj->u_o.cy.min - ray->o.y) / ray->dir.y;
	if (check_caps(ray, itx.t))
	{
		itxv_add(itxv, &itx);
		has_hit = true;
	}
	itx.t = (obj->u_o.cy.max - ray->o.y) / ray->dir.y;
	if (check_caps(ray, itx.t))
	{
		itxv_add(itxv, &itx);
		has_hit = true;
	}
	return (has_hit);
}

static bool intersect_walls(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_pol2	cyl_eq;
	t_itx	itx;
	double	height;
	bool	hit;

	hit = false;
	cyl_eq.a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	if (deql(cyl_eq.a, 0.0))
		return (hit);
	cyl_eq.b = 2 * ray->o.x * ray->dir.x + 2 * ray->o.z * ray->dir.z;
	cyl_eq.c = ray->o.x * ray->o.x + ray->o.z * ray->o.z - 1;
	cyl_eq.delta = cyl_eq.b * cyl_eq.b - (4 * cyl_eq.a * cyl_eq.c);
	if (cyl_eq.delta < 0.0)
		return (hit);
	itx.obj = obj;
	itx.t = (-cyl_eq.b - sqrt(cyl_eq.delta)) / (2.0 * cyl_eq.a);
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.cy.min && height < obj->u_o.cy.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}
	itx.t = (-cyl_eq.b + sqrt(cyl_eq.delta)) / (2.0 * cyl_eq.a);
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.cy.min && height < obj->u_o.cy.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}	
	return (hit);
}

bool	cld_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv)
{
	
	t_ray	trf_ray;
	bool	hit;
	
	ray_trf(r, &(obj->itm), &trf_ray);
	if (intersect_walls(obj, &trf_ray, itxv))
		hit = true;
	if (intersect_caps(obj, &trf_ray, itxv))
		hit = true;
	return (hit);
}