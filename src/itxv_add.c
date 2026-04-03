/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itxv_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:30:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 12:40:09 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	itxv_add(t_itxv *itxv, const t_itx *itx)
{
	t_itx	*new_v;
	size_t	new_cap;

	if (!itxv || !itx)
		return (-1);
	if (itxv->len >= itxv->cap)
	{
		if (itxv->cap == 0)
			new_cap = 1;
		else
			new_cap = itxv->cap * 2;
		new_v = malloc(sizeof(t_itx) * new_cap);
		if (!new_v)
			return (-1);
		ft_memcpy(new_v, itxv->v, sizeof(t_itx) * itxv->cap);
		itxv->v = new_v;
		itxv->cap = new_cap;
	}
	itxv->v[itxv->len] = *itx;
	itxv->len++;
	return (0);
}
