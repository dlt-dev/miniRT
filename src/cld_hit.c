/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cld_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:03:27 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/29 07:57:23 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void	solve_eq(t_pol2 *cyl_eq, const t_ray *ray)
{
	cyl_eq->a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	cyl_eq->b = 2 * ray->o.x * ray->dir.x + 2 * ray->o.z * ray->dir.z;
	cyl_eq->c = ray->o.x * ray->o.x + ray->o.z * ray->o.z - 1;
	cyl_eq->delta = cyl_eq->b * cyl_eq->b - (4 * cyl_eq->a * cyl_eq->c);
	if (cyl_eq->delta >= 0.0 && !deql(cyl_eq->a, 0.0))
	{
		cyl_eq->r1 = (-cyl_eq->b - sqrt(cyl_eq->delta)) / (2.0 * cyl_eq->a);
		cyl_eq->r2 = (-cyl_eq->b + sqrt(cyl_eq->delta)) / (2.0 * cyl_eq->a);
	}
	else
	{
		cyl_eq->r1 = NAN;
		cyl_eq->r2 = NAN;
	}
}

static bool	solve_root(t_pol2 *cyl_eq, const t_ray *ray,
	const t_obj *obj, t_itxv *itxv)
{
	t_itx	itx;
	bool	hit;
	double	height;

	hit = false;
	itx.obj = obj;
	itx.t = cyl_eq->r1;
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.cy.min && height < obj->u_o.cy.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}
	itx.t = cyl_eq->r2;
	height = ray->o.y + itx.t * ray->dir.y;
	if (height > obj->u_o.cy.min && height < obj->u_o.cy.max)
	{
		itxv_add(itxv, &itx);
		hit = true;
	}
	return (hit);
}

static bool	intersect_walls(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_pol2	cyl_eq;
	bool	hit;

	hit = false;
	solve_eq(&cyl_eq, ray);
	if (deql(cyl_eq.a, 0.0))
		return (hit);
	if (cyl_eq.delta < 0.0)
		return (hit);
	hit = solve_root(&cyl_eq, ray, obj, itxv);
	return (hit);
}

// In cld_hit2.c
bool	cld_intersect_caps(const t_obj *obj, const t_ray *ray, t_itxv *itxv);

bool	cld_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv)
{
	t_ray	trf_ray;
	bool	hit;

	ray_trf(r, &(obj->itm), &trf_ray);
	hit = false;
	if (intersect_walls(obj, &trf_ray, itxv))
		hit = true;
	if (cld_intersect_caps(obj, &trf_ray, itxv))
		hit = true;
	return (hit);
}
