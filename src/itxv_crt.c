/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itxv_crt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:26:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 12:29:23 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_itxv	itxv_crt(size_t cap)
{
	t_itxv	itxv;

	itxv.len = 0;
	itxv.cap = cap;
	if (cap == 0)
	{
		itxv.v = NULL;
		return (itxv);
	}
	itxv.v = malloc(sizeof(t_itx) * cap);
	if (!itxv.v)
		itxv.cap = 0;
	return (itxv);
}
