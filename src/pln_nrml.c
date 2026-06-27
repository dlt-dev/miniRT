/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln_nrml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:01:47 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:37:37 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	pln_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml)
{
	const t_v4	base = v4_crt(0, 1, 0);

	(void) pt;
	if (!obj || !nrml)
		return (-1);
	m44_vprd(&(obj->itm), &base, nrml);
	return (0);
}
