/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itx_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:33:07 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 12:16:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	itx_prt(const t_itx *itx)
{
	printf("Intersection :\n");
	printf("t: %f\n", itx->t);
	printf("hitpoint");
	v4_lprt((t_v4 *)(&itx->hp));
	printf("\nray_direction");
	v4_lprt(&(itx->rd));
	printf("\nsurface_normal");
	v4_lprt(&(itx->nrm));
	printf("\n");
}
