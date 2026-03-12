/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pln_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:42:56 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/12 11:43:04 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ray_pln_intersection(t_ray *ray, t_pln *plane, double *t)
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
	return (false);
}
