/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:59:08 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:59:50 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

t_itv	itv_crt(double min, double max)
{
	t_itv	itv;

	itv.min = min;
	itv.max = max;
	return (itv);
}
