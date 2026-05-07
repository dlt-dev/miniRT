/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:04:01 by cybourge          #+#    #+#             */
/*   Updated: 2026/05/06 13:58:49 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

bool	pln_hit(const t_obj *obj, const t_ray *ray, t_itxv *itxv)
{
	t_itx	itx;
	t_ray	trf_ray;
	t_m44	idm;

	m44_idm(&idm);
	ray_trf(ray, &(obj->itm), &trf_ray);
	if (deql(trf_ray.dir.y, 0.0))
		return (false);
	itx.obj = obj;
	itx.t = -trf_ray.o.y / trf_ray.dir.y;
	itxv_add(itxv, &itx);
	return (true);
}
