/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 07:59:11 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/22 09:18:12 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H


# include "color.h"
# include "vector4.h"
# include "matrix.h"
# include "transformations.h"

typedef struct s_pattern
{
	t_m44	tm;
	t_m44	itm;
	t_clr	(*pat)(const struct s_pattern *, const t_pt *);
	t_clr	clr1;
	t_clr	clr2;
}	t_pat;

// Applies the transformations to the pattern.
// Returns -1 on error, 0 otherwise.
int		pat_trf(t_pat *pat, const t_trf *trf);

// returns the color of a vertical stripped pattern at point p
t_clr	pat_strp1(const t_pat *pat, t_pt const *p);

// returns the color of a gradient pattern.
t_clr	pat_lgrad1(const t_pat *pat, t_pt const *p);

// returns the color of a ring pattern.
t_clr	pat_ring1(const t_pat *pat, t_pt const *p);

// returns the color of a Checker pattern.
t_clr	pat_chkr1(const t_pat *pat, t_pt const *p);


#endif