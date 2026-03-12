/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/18 09:45:44 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// returns true if value is in the interval, false otherwise
bool	itv_contains(t_itv *interval, double value)
{
	return (interval->min <= value && value <= interval->max);
}
