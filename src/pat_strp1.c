/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_strp1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:04:34 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/16 08:59:48 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_clr	pat_strp1(const t_pat *pat, t_pt const *p)
{
	t_pt	pat_pt;

	m44_vprd(&(pat->itm), p, &pat_pt);
	if (((int) floor(pat_pt.x) % 2) == 0)
		return (pat->clr1);
	return (pat->clr2);
}
