/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_gclr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:56:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 09:54:10 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_clr	obj_gclr(const t_obj *obj, const t_pt *p)
{
	t_pt	obj_pt;

	//m44_vprd(&(obj->itm), p, &obj_pt);
	obj_pt = *p;
	if (obj->mtrl.pat == STRIPPED_X)
		return (pat_strp1(&obj_pt));
	else if (obj->mtrl.pat == LIN_GRAD_X)
		return (pat_lgrad1(&obj_pt));
	else if (obj->mtrl.pat == RING_XZ)
		return (pat_ring1(&obj_pt));
	else if (obj->mtrl.pat == CHECKER)
		return (pat_chkr1(&obj_pt));
	else
		return (obj->mtrl.clr);
}
