/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_gclr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:56:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 13:42:21 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_clr	obj_gclr(const t_obj *obj, const t_pt *p)
{
	t_pt	obj_pt;
	t_pt	pat_pt;
	t_pt	fin_pt;

	if (obj->mtrl.tex == NULL)
		return (obj->mtrl.clr);
	m44_vprd(&(obj->itm), p, &obj_pt);
	m44_vprd(&(obj->mtrl.itm), &obj_pt, &pat_pt);
	if (obj->gcord != NULL)
		fin_pt = obj->gcord(&pat_pt);
	else
		fin_pt = pat_pt;
	if (obj->mtrl.tex->type == FILE_TEX)
		return (ftex_clr(&(obj->mtrl.tex->u_tex.ftex), &fin_pt));
	else if (obj->mtrl.tex->type == PATTERN_TEX)
		return (obj->mtrl.tex->u_tex.ptex.pat(obj->mtrl.tex, &fin_pt));
	else
		return (obj->mtrl.clr);
}
