/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_isin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/04 14:56:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"


// returns true if value is in the interval, false otherwise
bool	itv_isin(t_itv *interval, double value)
{
	
	if (interval->max_included == true && interval->min_included == true)
	{
		if (value <= interval->max && value >= interval->min)
			return (true);
	}
	if (interval->max_included == false && interval->min_included == false)
	{
		if (value < interval->max && value > interval->min)
			return (true);
	}
	if (interval->max_included == true && interval->min_included == false)
	{
		if (value <= interval->max && value > interval->min)
			return (true);
	}
	if (interval->max_included == false && interval->min_included == true)
	{
		if (value < interval->max && value >= interval->min)
			return (true);
	}
	return (false);
}
