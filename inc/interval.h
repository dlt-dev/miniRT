/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:39:53 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:57:08 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_H
# define INTERVAL_H

# include <stdbool.h>

typedef struct s_interval
{
	double	min;
	double	max;
}	t_itv;

// Returns an interval defined by the parameters.
t_itv	itv_crt(double min, double max);

// Clamps the value x to the interval.
double	itv_clp(t_itv interval, double x);
// Returns wether x is contained in interval : x ∈ [min,max].
bool	itv_cnt(t_itv interval, double x);
// Returns wether x is surrounded by interval : x ∈ ]min, max[.
bool	itv_srd(t_itv interval, double x);

#endif