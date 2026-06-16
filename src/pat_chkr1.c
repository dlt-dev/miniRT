/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_chkr1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:44:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/16 08:58:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_clr	pat_chkr1(const t_pat *pat, t_pt const *p)
{
	t_pt	pat_pt;

	m44_vprd(&(pat->itm), p, &pat_pt);
	if ((int)(floor(pat_pt.x) + floor(pat_pt.y) + floor(pat_pt.z)) % 2 == 0)
		return (pat->clr1);
	return (pat->clr2);
}
