/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_lgrad1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:26:59 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 10:20:56 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_clr	pat_lgrad1(const t_tex *tex, t_pt const *p)
{
	const t_clr		dst = clr_sub(tex->u_tex.ptex.clr2, tex->u_tex.ptex.clr1);
	double			step;

	step = p->x - floor(p->x);
	return (clr_add(tex->u_tex.ptex.clr1, clr_mul(dst, step)));
}
