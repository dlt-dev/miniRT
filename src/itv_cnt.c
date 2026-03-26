/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 10:30:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

bool	itv_cnt(t_itv interval, double value)
{
	return (interval.min <= value && value <= interval.max);
}
