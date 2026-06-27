/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_chkr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:18:02 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:26:30 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

// P are (u,v) coordinates : u,v are in [0,1]
// Rectangle Checkers pattern.
t_clr	pat_chkr2(const t_tex *tex, t_pt const *p)
{
	double	u2;
	double	v2;

	u2 = floor(p->x * 4);
	v2 = floor(p->y * 4 * 2);
	if ((int)(u2 + v2) % 2 == 0)
		return (tex->u_tex.ptex.clr1);
	else
		return (tex->u_tex.ptex.clr2);
}
