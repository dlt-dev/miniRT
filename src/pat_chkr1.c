/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_chkr1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:44:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:17:49 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

// P are (u,v) coordinates : u,v are in [0,1]
// Square Checkers pattern.
t_clr	pat_chkr1(const t_tex *tex, t_pt const *p)
{
	double	u2;
	double	v2;

	u2 = floor(p->x * 2);
	v2 = floor(p->y * 2);
	if ((int)(u2 + v2) % 2 == 0)
		return (tex->u_tex.ptex.clr1);
	else
		return (tex->u_tex.ptex.clr2);
}
