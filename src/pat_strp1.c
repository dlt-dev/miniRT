/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_strp1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:04:34 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 09:52:21 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_clr	pat_strp1(t_pt const *p)
{
	// Need OBJ to Pattern space conversion here
	if (((int) floor(p->x) % 2) == 0)
		return (clr_unpack(RED));
	return (clr_unpack(WHITE));
}
