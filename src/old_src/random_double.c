/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:28:23 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/10 08:50:22 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double ft_random()
{
	return (rand() / (RAND_MAX + 1.0));
}

double	random_double(double min, double max)
{
	return (min + (max - min) * ft_random());
}