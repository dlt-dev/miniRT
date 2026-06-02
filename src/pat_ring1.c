/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_ring1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:36:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 09:51:54 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_clr	pat_ring1(t_pt const *p)
{
	// Need OBJ to Pattern space conversion here
	if ((int) floor(sqrt(p->x * p->x + p->z * p->z)) % 2 == 0)
		return (clr_unpack(WHITE));
	return (clr_unpack(BLUE));
}
