/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itx_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 08:12:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 16:20:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "object.h"

static int	set_refraction(t_itx *itx, const t_itxv *itxv)
{
	t_objl	*objl;
	size_t	i;

	i = 0;
	objl = NULL;
	while (i < itxv->len)
	{
		if (itxv->v[i].t == itx->t)
		{
			if (!objl || !objl->obj)
				itx->n1 = 1.0;
			else
				itx->n1 = objl_last(objl)->mtrl.ref;
		}
		if (objl_isin(objl, itxv->v[i].obj))
			objl_dlt(&objl, itxv->v[i].obj);
		else
		{
			if (objl_add(&objl, itxv->v[i].obj) == -1)
			{
				objl_free(objl);
				return (ft_err_prt("Could not add object to list\n", -1));
			}
		}
		if (itxv->v[i].t == itx->t)
		{
			if (!objl || !objl->obj)
				itx->n2 = 1.0;
			else
				itx->n2 = objl_last(objl)->mtrl.ref;
			objl_free(objl);
			return (0);
		}
		i++;
	}
	return (-1);
}

// static void	tnb_m44(t_m44 *tnb, t_v4 *world_normal)
// {
// 	t_v4	t;
// 	t_v4	b;

// 	t = v4_xpr(*world_normal, v4_crt(0, 1, 0));
// 	if (deql(v4_len(t), 0.0))
// 		t = v4_xpr(*world_normal, v4_crt(0, 0, 1));
// 	t = v4_uni(t);
// 	b = v4_uni(v4_xpr(*world_normal, t));
// 	(*tnb)[0] = t.x;
// 	(*tnb)[1] = t.y;
// 	(*tnb)[2] = t.z;
// 	(*tnb)[3] = t.w;
// 	(*tnb)[4] = b.x;
// 	(*tnb)[5] = b.y;
// 	(*tnb)[6] = b.z;
// 	(*tnb)[7] = b.w;
// 	(*tnb)[8] = world_normal->x;
// 	(*tnb)[9] = world_normal->y;
// 	(*tnb)[10] = world_normal->z;
// 	(*tnb)[11] = world_normal->w;
// 	(*tnb)[12] = 0.0;
// 	(*tnb)[13] = 0.0;
// 	(*tnb)[14] = 0.0;
// 	(*tnb)[15] = 1.0;
// }

int	itx_cal(t_itx *itx, const t_ray *ray, const t_itxv *itxv)
{
	if (!itx || !(itx->obj))
		return (-1);
	if (set_refraction(itx, itxv) == -1)
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
	itx->uhp = v4_sub(itx->hp, v4_mul(itx->nrm, EPS));
	itx->rflv = v4_rfl(&(ray->dir), &(itx->nrm));
	return (0);
}
