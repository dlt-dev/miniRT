/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_chkr1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:44:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/24 14:19:00 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

// P are (u,v) coordinates : u,v are in [0,1]
t_clr	pat_chkr1(const t_pat *pat, t_pt const *p)
{
	//t_pt	pat_pt;
	double	u2;
	double	v2;
	//double	w2;

	//m44_vprd(&(pat->itm), p, &pat_pt);
	// u2 = floor(pat_pt.x * 4);
	// v2 = floor(pat_pt.y * 4);
	// w2 = floor(pat_pt.z * 4);
	// if ((int)(u2 + v2 + w2) % 2 == 0)
	// 	return (pat->clr1);
	// else
	// 	return (pat->clr2);
	u2 = floor(p->x * 4);
	v2 = floor(p->y * 4);
	if ((int)(u2 + v2) % 2 == 0)
		return (pat->clr1);
	else
		return (pat->clr2);
}
