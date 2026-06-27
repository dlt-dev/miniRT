/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_hit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:46:39 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:09:25 by cybourge         ###   ########.fr       */
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

bool	con_intersect_caps(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
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
