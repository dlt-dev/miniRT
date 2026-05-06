/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln_nrml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:01:47 by cybourge          #+#    #+#             */
/*   Updated: 2026/05/06 13:36:56 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	pln_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml)
{
	(void) pt;
	if (!obj || !nrml)
		return (-1);
	nrml->x = obj->u_o.pl.nrml.x;
	nrml->y = obj->u_o.pl.nrml.y;
	nrml->z = obj->u_o.pl.nrml.z;
	nrml->w = 0;
	return (0);
}
