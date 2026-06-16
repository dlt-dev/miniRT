/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_lgrad1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:26:59 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/16 08:59:05 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_clr	pat_lgrad1(const t_pat *pat, t_pt const *p)
{
	const t_clr		dst = clr_sub(pat->clr2, pat->clr1);
	double			step;
	t_pt			pat_pt;

	m44_vprd(&(pat->itm), p, &pat_pt);
	step = pat_pt.x - floor(pat_pt.x);
	return (clr_add(pat->clr1, clr_mul(dst, step)));
}
