/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itv_clamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:53:39 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/18 13:55:59 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	itv_clamp(t_itv *interval, double x)
{
	if (x < interval->min)
		return (interval->min);
	if (x > interval->max)
		return (interval->max);
	return (x);
}