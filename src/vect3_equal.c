/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_equal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:37:36 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 14:52:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

bool	double_equal(double a, double b)
{
	return (fabs(a - b) < EPS);
}

bool	vect3_equal(t_vect3 a, t_vect3 b)
{
	return (double_equal(a.x, b.x) && double_equal(a.y, b.y)
		&& double_equal(a.z, b.z));
}
