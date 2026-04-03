/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itxv_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:42:02 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 12:44:10 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_itx	itxv_hit(const t_itxv *itxv)
{
	size_t	i;
	t_itx	no_hit;

	no_hit.obj = NULL;
	no_hit.t = NAN;
	if (!itxv)
		return (no_hit);
	i = 0;
	while (i < itxv->len)
	{
		if (itxv->v[i].t >= 0)
			return (itxv->v[i]);
		i++;
	}
	return (no_hit);
}
