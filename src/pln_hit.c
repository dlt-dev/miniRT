/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:36:58 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/10 08:56:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	pln_hit(t_pln *plane, t_ray *ray, t_hitinfo *info, t_itv *interval)
{
	t_vect3 oc;
	double denom;
	double t;

	/* n · dir */
	denom = vect3_dot(plane->nnv, ray->dir);
	if (double_equal(denom, 0.0))
		return (false);

	/* t = n · (A - O) / (n · dir) */
	oc = vect3_sub(plane->p, ray->o);
	t = vect3_dot(oc, plane->nnv) / denom;

	/* interval check */
	if (t < interval->min || t > interval->max)
		return (false);

	info->t = t;

	/* p = O + tD */
	info->p = vect3_add(ray->o, vect3_mul_scalar(ray->dir, t));

	/* determine face */
	info->front_face = vect3_dot(ray->dir, plane->nnv) < 0;

	if (info->front_face)
		info->n = plane->nnv;
	else
		info->n = vect3_inv(plane->nnv);

	return (true);
}