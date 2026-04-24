/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:19:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 09:47:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_clr	obj_lgt(const t_obj *obj, const t_lgt *light, const t_itx *data, bool shadowed)
{
	t_obj_lgt	l;

	l.eff_clr = clr_bld(obj->mtrl.clr, light->clr);
	l.lightv = v4_uni(v4_sub(light->pos, data->hp));
	l.ambient = clr_mul(l.eff_clr, obj->mtrl.amb);
	l.ldn = v4_dot(l.lightv, data->nrm);
	if (l.ldn < 0 || shadowed)
	{
		l.diffuse = clr_unpack(BLACK);
		l.specular = clr_unpack(BLACK);
	}
	else
	{
		l.diffuse = clr_mul(l.eff_clr, obj->mtrl.dif * l.ldn);
		l.nlightv = v4_inv(l.lightv);
		l.reflectv = v4_rfl(&l.nlightv, &(data->nrm));
		l.rdrd = v4_dot(l.reflectv, data->rd);
		if (l.rdrd <= 0)
			l.specular = clr_unpack(BLACK);
		else
			l.specular = clr_mul(light->clr,
					obj->mtrl.spc * pow(l.rdrd, obj->mtrl.shi));
	}
	return (clr_add(l.ambient, clr_add(l.diffuse, l.specular)));
}
