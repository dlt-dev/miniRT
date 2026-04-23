/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:41:30 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:42:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_clr	clr_crt(double t, double r, double g, double b)
{
	t_clr	clr;

	clr.t = t;
	clr.r = r;
	clr.g = g;
	clr.b = b;
	return (clr);
}
