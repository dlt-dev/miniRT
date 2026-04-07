/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itxv_prt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 08:52:59 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 08:55:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	itxv_prt(const t_itxv *itxv)
{
	size_t	i;

	if (!itxv || !itxv->v)
		return ;
	printf("Intersection (%zu) : [", itxv->len);
	i = 0;
	while (i < itxv->len)
	{
		printf("%f", itxv->v[i].t);
		if (i + 1 < itxv->len)
			printf(", ");
		i++;
	}
	printf("]\n");
}
