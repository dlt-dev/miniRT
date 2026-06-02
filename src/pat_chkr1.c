/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_chkr1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:44:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 09:53:48 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_clr	pat_chkr1(t_pt const *p)
{
	// Need OBJ to Pattern space conversion here
	if ((int)(floor(p->x) + floor(p->y) + floor(p->z)) % 2 == 0)
		return (clr_unpack(WHITE));
	return (clr_unpack(BLACK));
}
