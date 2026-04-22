/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:19:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:41:10 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_clr	obj_lgt(const t_obj *obj, const t_lgt *light, const t_itx *data)
{
	t_obj_lgt	l;

	l.eff_clr = clr_bld(obj->mtrl.clr, light->clr);
	l.lightv = v4_uni(v4_sub(light->pos, data->hp));
	l.ambient = clr_mul(l.eff_clr, obj->mtrl.amb);
	l.ldn = v4_dot(l.lightv, data->nrm);
	if (l.ldn < 0)
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

// t_clr	obj_lgt(const t_obj *obj, const t_lgt *light, const t_itx *data)
// {
// 	t_clr	eff_clr;
// 	t_clr	ambient;
// 	t_clr	diffuse;
// 	t_clr	specular;
// 	t_v4	lightv;
// 	t_v4	nlightv;
// 	t_v4	reflectv;
// 	double	ldn; // lightv dot normal
// 	double	rdrd; // light reflect dot raydir

// 	eff_clr = clr_bld(obj->mtrl.clr, light->clr);
// 	lightv = v4_uni(v4_sub(light->pos, data->hp));
// 	ambient = clr_mul(eff_clr, obj->mtrl.amb);
// 	ldn = v4_dot(lightv, data->nrm);
// 	if (ldn < 0)
// 	{
// 		diffuse = clr_unpack(BLACK);
// 		specular = clr_unpack(BLACK);
// 	}
// 	else
// 	{
// 		diffuse = clr_mul(eff_clr, obj->mtrl.dif * ldn);
// 		nlightv = v4_inv(lightv);
// 		reflectv = v4_rfl(&nlightv, &(data->nrm));
// 		rdrd = v4_dot(reflectv, data->rd);
// 		if (rdrd <= 0)
// 			specular = clr_unpack(BLACK);
// 		else
// 			specular = clr_mul(light->clr, obj->mtrl.spc * pow(rdrd, obj->mtrl.shi));
// 	}
// 	return (clr_add(ambient, clr_add(diffuse, specular)));
// }
