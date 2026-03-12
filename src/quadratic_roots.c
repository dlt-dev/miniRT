/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_roots.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:42:08 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/12 11:42:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int quadratic_roots(double a, double b, double c, t_tuple *roots)
{
	double discriminant = (b * b) - 4 * a * c;
	if (discriminant > EPS)
	{
		double b_term;
		if (b < EPS)
			b_term = -b + sqrt(discriminant);	
		else
			b_term = -b - sqrt(discriminant);
		roots->x = b_term / (2.0 * a);
		roots->y = (2.0 * c) / b_term;
		if (roots->x > roots->y)
		{
			double tmp;
			tmp = roots->x;
			roots->x = roots->y;
			roots->y = tmp;
		}
		return (2);
	}
	else if (discriminant > -EPS && discriminant <= EPS)
	{
		roots->x = -(b / (2.0 * a));
		roots->y = roots->x;
		return (1);
	}
	else
	{
		roots->x = NAN;
		roots->y = NAN;
		return (0);
	}
}
