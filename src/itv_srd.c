/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_srd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:50:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 10:35:03 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

bool	itv_srd(t_itv interval, double value)
{
	return (interval.min < value && value < interval.max);
}
