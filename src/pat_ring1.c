/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_ring1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:36:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 12:25:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_clr	pat_ring1(const t_tex *tex, t_pt const *p)
{
	if ((int) floor(sqrt(p->x * p->x + p->y * p->y)) % 2 == 0)
		return (tex->u_tex.ptex.clr1);
	return (tex->u_tex.ptex.clr2);
}
