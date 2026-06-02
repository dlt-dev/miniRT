/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 07:59:11 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 09:52:51 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "color.h"
# include "vector4.h"
# include "matrix.h"
# include "transformations.h"

// Pattern types
typedef enum e_pat_types
{
	NONE = 0,
	STRIPPED_X,
	LIN_GRAD_X,
	RING_XZ,
	CHECKER
}	t_patt;

// returns the color of a X vertical stripped pattern RED and WHITE at point p
t_clr	pat_strp1(t_pt const *p);

// returns the color of a gradient pattern between RED and BLUE.
t_clr	pat_lgrad1(t_pt const *p);

// returns the color of a ring pattern WHITE BLUE.
t_clr	pat_ring1(t_pt const *p);

// returns the color of a WHITE BLACK Checker pattern.
t_clr	pat_chkr1(t_pt const *p);

#endif