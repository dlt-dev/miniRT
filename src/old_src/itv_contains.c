/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/24 09:56:07 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// returns true if value is in the interval, false otherwise
bool	itv_contains(const t_itv *interval, double value)
{
	return (interval->min <= value && value <= interval->max);
}
