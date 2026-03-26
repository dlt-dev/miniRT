/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pln_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:42:56 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/25 08:24:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ray_pln_intersection(const t_ray *ray, const t_pln *plane, double *t)
{
	double denom = vect3_dot(plane->nnv, ray->dir);

	if (denom > EPS || denom < -EPS)
	{
		double Hd = vect3_dot(vect3_sub(plane->p, ray->o), plane->nnv) / denom;
		if (Hd >= 0)
		{
			*t = Hd;
			return (true);
		}	
	}
	*t = NAN;
	return (false);
}
