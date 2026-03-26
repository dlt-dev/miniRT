/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_clp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:53:39 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 10:34:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

double	itv_clp(t_itv interval, double x)
{
	if (x < interval.min)
		return (interval.min);
	if (x > interval.max)
		return (interval.max);
	return (x);
}
