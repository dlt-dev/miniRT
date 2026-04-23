/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:38:16 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 13:58:50 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "interval.h"
# include <stdint.h>
# define BLACK	0x00000000
# define WHITE	0x00FFFFFF
# define BLUE	0x001F31FF
# define RED	0x00B51922

typedef struct color
{
	double	t;
	double	r;
	double	g;
	double	b;	
}			t_clr;

// Returns a color defined by the parameters.
t_clr		clr_crt(double t, double r, double g, double b);

// color addition
t_clr		clr_add(t_clr c1, t_clr c2);
// color substraction
t_clr		clr_sub(t_clr c1, t_clr c2);
// color multiplying
t_clr		clr_mul(t_clr c1, double i);
// color blending
t_clr		clr_bld(t_clr c1, t_clr c2);

// TRGB OPERATIONS
// Returns the color c in its trgb hexadecimal form.
uint32_t	clr_pack(t_clr c);
// Returns the color c corresponding to the trgb hexadecimal color.
t_clr		clr_unpack(uint32_t packed);

#endif