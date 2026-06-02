/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_lgrad1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:26:59 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 12:03:02 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_clr	pat_lgrad1(const t_pat *pat, t_pt const *p)
{
	const t_clr		clr1 = clr_unpack(RED);
	const t_clr		clr2 = clr_unpack(BLUE);
	const t_clr		dst = clr_sub(clr2, clr1);
	double			step;
	t_pt			pat_pt;

	m44_vprd(&(pat->itm), p, &pat_pt);
	step = pat_pt.x - floor(pat_pt.x);
	return (clr_add(clr1, clr_mul(dst, step)));
}
