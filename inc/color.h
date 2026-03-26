/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:38:16 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 10:12:38 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

#include "interval.h"

typedef struct color
{
	double	r;
	double	g;
	double	b;
	double	t;
}			t_clr;

// color addition
t_clr	clr_add(t_clr c1, t_clr c2);
// color substraction
t_clr	clr_sub(t_clr c1, t_clr c2);
// color multiplying
t_clr	clr_mul(t_clr c1, double i);
// color blending
t_clr	clr_bld(t_clr c1, t_clr c2);



#endif