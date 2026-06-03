/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itx_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 08:12:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 14:02:19 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "object.h"

int	itx_cal(t_itx *itx, const t_ray *ray)
{
	if (!itx || !(itx->obj))
		return (-1);
	itx->hp = ray_pos(ray, itx->t);
	itx->rd = v4_inv(ray->dir);
	if (itx->obj->nrml(itx->obj, &(itx->hp), &(itx->nrm)) == -1)
		return (-1);
	if (v4_dot(itx->nrm, itx->rd) < 0)
	{
		itx->in = true;
		itx->nrm = v4_inv(itx->nrm);
	}
	else
		itx->in = false;
	itx->ohp = v4_add(itx->hp, v4_mul(itx->nrm, EPS));
	itx->rflv = v4_rfl(&(ray->dir), &(itx->nrm));
	return (0);
}
