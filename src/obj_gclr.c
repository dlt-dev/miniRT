/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_gclr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:56:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 13:22:51 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_clr	obj_gclr(const t_obj *obj, const t_pt *p)
{
	t_pt	obj_pt;

	if (obj->mtrl.pat.pat == NULL)
		return (obj->mtrl.clr);
	m44_vprd(&(obj->itm), p, &obj_pt);
	return (obj->mtrl.pat.pat(&(obj->mtrl.pat), &obj_pt));
}
