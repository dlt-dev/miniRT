/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgtv_prt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:45:30 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:16:04 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void	lgtv_prt(const t_lgtv *lgtv)
{
	size_t	i;

	printf("Lights (%ld) : \n", lgtv->len);
	i = 0;
	while (i < lgtv->len)
	{
		printf("pos");
		v4_lprt(&(lgtv->v[i].pos));
		printf(", color");
		v4_lprt((const t_v4 *)&(lgtv->v[i].clr));
		printf("\n");
		i++;
	}
	if (i == 0)
		printf("\n");
}
