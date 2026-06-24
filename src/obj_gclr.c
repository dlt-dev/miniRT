/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_gclr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:56:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 16:10:17 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_clr	obj_gclr(const t_obj *obj, const t_pt *p)
{
	t_pt	obj_pt;
	t_pt	pat_pt;

	m44_vprd(&(obj->itm), p, &obj_pt);
	m44_vprd(&(obj->mtrl.pat.itm), &obj_pt, &pat_pt);
	if (obj->gcord != NULL)
		obj_pt = obj->gcord(&pat_pt);
	// Texture mapping goes here.
	if (obj->mtrl.tex.h != 0 && obj->mtrl.tex.w != 0)
	{
		return (ftex_clr(&(obj->mtrl.tex), &obj_pt));
	}
	if (obj->mtrl.pat.pat == NULL)
		return (obj->mtrl.clr);
	return (obj->mtrl.pat.pat(&(obj->mtrl.pat), &obj_pt));
}
